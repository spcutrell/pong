#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class Game {
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        bool exit;
    public:
        Game(int argc, char *argv[]);
        ~Game();

        void executeGameLoop();
        void handleInput();
        void render();
};

Game::Game(int argc, char *argv[]) {

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_ShowCursor(0);

    window = SDL_CreateWindow(
            "Pong",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH,
            SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN
    );

    renderer = SDL_CreateRenderer(
            window,
            -1,
            SDL_RENDERER_ACCELERATED
    );

    exit = false;
};

Game::~Game() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Game::handleInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            exit = true;
        }
    }
}

void Game::render() {
    //SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_SetRenderDrawColor(renderer, 102, 0, 51, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

void Game::executeGameLoop() {
    while (!exit) {
        handleInput();
    }
}

int main(int argc, char *argv[]) {
    Game game(argc, argv);
    game.executeGameLoop();
    return 0;
}
