#include <Windows.h>
#include <boost/di.hpp>
#include <iostream>
#include <utility>

#include "Game/Game.h"
#include "Graphics/IRender.h"
#include "Graphics/Renders/ASCIIRender.h"
#include "Scenes/TestScene.h"
#include "Utils/Console.h"

namespace di = boost::di;

auto di_injector =
        di::make_injector(di::bind<Utils::IConsole>().to<Utils::Console>(),
                          di::bind<Graphics::IRender>().to([](const auto& lambda_injector) {
                              auto console = lambda_injector.template create<std::unique_ptr<Utils::IConsole>>();
                              return std::unique_ptr<Graphics::IRender>(
                                      std::make_unique<Graphics::ASCIIRender>(30, 30, 60.0, std::move(console)));
                          }),
                          di::bind<Game::IScene>().to([] {
                              return std::unique_ptr<Game::IScene>(std::make_unique<Scenes::TestScene>(30, 30));
                          }),
                          di::bind<Game::Game>().to<Game::Game>());

int main() {
    const auto game = di_injector.create<std::unique_ptr<Game::Game>>();

    try {
        game->Run();
    } catch (const std::exception& e) {
        HWND hwnd = GetConsoleWindow();
        const int size_needed = MultiByteToWideChar(CP_ACP, 0, e.what(), -1, nullptr, 0);
        std::wstring wide_str_exception(size_needed, L'\0');
        MultiByteToWideChar(CP_ACP, 0, e.what(), -1, &wide_str_exception[0], size_needed);
        MessageBoxW(hwnd, wide_str_exception.c_str(), L"Runtime error", MB_ICONERROR | MB_OK);
    }
    return 0;
}
