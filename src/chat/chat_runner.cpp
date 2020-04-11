#include "chat_runner.hpp"

#include <raylib.h>

#include "../ui2/vertical_layout.hpp"
#include "../ui2/wigets.hpp"
#include "chat.hpp"

using namespace std;

static void Update(Chat& chat) {
  auto chatList = ui2::VerticalLayout({0, 0});

  for (const auto& user : chat.GetUsers()) {
    if (ui2::Button(&chatList, user)) {
      chat.selectedUser = user;
    }
  }

  auto chatBody = ui2::VerticalLayout({300, 0});
  ui2::Label(&chatBody, chat.selectedUser);
}

void RunChat() {
  int screenWidth = 800;
  int screenHeight = 600;
  InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");
  SetTargetFPS(30);

  Chat chat;
  chat.AddUser("Support");
  chat.AddUser("__Me__");
  chat.AddUser("jijog_bfgasher");
  chat.AddUser("55_maximus_55");
  chat.AddUser("ILoveYourMotherAndOther");
  chat.AddUser("reuszzz7");

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    Update(chat);

    EndDrawing();
  }

  CloseWindow();
}