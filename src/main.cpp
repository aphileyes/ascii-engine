#include <Windows.h>
#include <boost/di.hpp>
#include <iostream>
#include <utility>

#include "Game/Game.h"

namespace di = boost::di;

int main() {
    const auto di_injector =
            di::make_injector(di::bind<Utils::IConsole>().to<Utils::Console>(),
                              di::bind<Graphics::IRender>().to([](const auto& lambda_injector) {
                                  auto console = lambda_injector.template create<std::unique_ptr<Utils::IConsole>>();
                                  return std::unique_ptr<Graphics::IRender>(
                                          std::make_unique<Graphics::ASCIIRender>(120, 30, 60.0, std::move(console)));
                              }),
                              di::bind<Game::Game>().to([](const auto& lambda_injector) {
                                  auto render = lambda_injector.template create<std::unique_ptr<Graphics::IRender>>();
                                  return std::make_unique<Game::Game>(std::move(render));
                              }));

    const auto game = di_injector.create<std::unique_ptr<Game::Game>>();

    try {
        game->Run();
    } catch (const std::exception& e) {
        HWND hwnd = GetConsoleWindow();
        /**
         * Преобразует строку исключения из многобайтовой кодировки в широкую строку Unicode.
         *
         * Этот код выполняет двухэтапное преобразование строки, возвращаемой методом {@link std::exception::what()},
         * из локальной кодовой страницы (например, Windows-1252) в формат Unicode (wchar_t) для отображения в
         * диалоговом окне Windows. Сначала определяется необходимый размер буфера с помощью вызова
         * {@link MultiByteToWideChar} с нулевым буфером, затем выделяется строка std::wstring и выполняется
         * окончательное преобразование.
         *
         * @param size_needed переменная, хранящая размер буфера в символах wchar_t, включая завершающий нуль
         * @param wide_str_exception результирующая широкая строка, содержащая преобразованную строку исключения
         * @param e.what() входная строка исключения в многобайтовой кодировке
         * @param CP_ACP кодовая страница системы (локальная кодировка, например, Windows-1252)
         * @param -1 длина входной строки, включая завершающий нулевой символ
         * @param nullptr указатель на выходной буфер (нулевой для определения размера)
         * @param 0 размер выходного буфера (нулевой для первого вызова)
         * @param &wide_str_exception[0] указатель на буфер строки для записи результата
         *
         * @throws std::bad_alloc если не удаётся выделить память для wide_str_exception
         * @throws std::runtime_error если преобразование завершается с ошибкой (проверяется через GetLastError)
         *
         * @see MessageBoxW
         */
        const int size_needed = MultiByteToWideChar(CP_ACP, 0, e.what(), -1, nullptr, 0);
        std::wstring wide_str_exception(size_needed, L'\0');
        MultiByteToWideChar(CP_ACP, 0, e.what(), -1, &wide_str_exception[0], size_needed);

        MessageBoxW(hwnd, wide_str_exception.c_str(), L"Runtime error", MB_ICONERROR | MB_OK);
    }
    return 0;
}
