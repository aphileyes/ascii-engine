#include <Windows.h>
#include <boost/di.hpp>
#include <iostream>
#include <thread>
#include <utility>

#include "Game/Game.h"
#include "Graphics/IRender.h"
#include "Graphics/Renders/ASCIIRender.h"
#include "IO/Handlers/Input.h"
#include "Scenes/TestScene.h"
#include "Utils/Console.h"

namespace di = boost::di;

int main() {
    auto di_injector = di::make_injector(
            di::bind<Utils::Console>().to<Utils::Console>(),
            di::bind<IO::IInput>().to([] { return std::unique_ptr<IO::IInput>(std::make_unique<IO::Input>()); }),
            di::bind<Game::IScene>().to(
                    [] { return std::unique_ptr<Game::IScene>(std::make_unique<Scenes::TestScene>(120, 30)); }),
            di::bind<Graphics::IRender>().to([](const auto& lambda_injector) {
                auto console = lambda_injector.template create<std::unique_ptr<Utils::Console>>();
                auto scene = lambda_injector.template create<std::unique_ptr<Game::IScene>>();
                return std::unique_ptr<Graphics::IRender>(std::make_unique<Graphics::ASCIIRender>(
                        scene->GetWidth(), scene->GetHeight(), 60, std::move(console)));
            }),
            di::bind<Game::Game>().to<Game::Game>());
    auto game = di_injector.create<std::unique_ptr<Game::Game>>();

    try {
        game->Run();
    } catch (const std::exception& e) {
        HWND hwnd = GetConsoleWindow();
        int size_needed = MultiByteToWideChar(CP_ACP, 0, e.what(), -1, nullptr, 0);
        std::wstring wide_str_exception(size_needed, L'\0');
        MultiByteToWideChar(CP_ACP, 0, e.what(), -1, &wide_str_exception[0], size_needed);
        MessageBoxW(hwnd, wide_str_exception.c_str(), L"Runtime error", MB_ICONERROR | MB_OK);
    }

    return 0;
}
