#include "chat_runner.hpp"

#include <raylib.h>

#include "../ui/absolute_layout.hpp"
#include "../ui/vertical_layout.hpp"
#include "chat.hpp"

using namespace std;

static void Update(Chat& chat) {
  AbsoluteLayout root;

  auto chatList = root.NewVerticalLayout(0, 0, 300);

  for (const auto& user: chat.GetUsers()) {
    if (chatList.Button(user, 32)) {
      chat.selectedUser = user;
    }
  }

  auto chatBody = root.NewVerticalLayout(chatList.GetPosX() + chatList.GetWidth(), 0, 500);
  chatBody.NewLabel(chat.selectedUser, 32);
  chatBody.NewWidget(600-32-96);

  //  Gui gui;
  //
  //  gui.button();
  //
  //  auto hz = gui.horizontal();
  //
  //  auto chatList = hz.verticalLayou();
  //
  //  chatList.button("Ilya", width=100%);
  //  chatList.button("twitch Chat");
  //  chatList.button("Sportloto");
  //
  //  auto chatBody = hz.verticalLayou();
  //
  //
  //  BeginHorizontalLayout();
  //
  //    BeginVerticalLayout();
  //    // chats list view
  //    EndVerticalLayout();
  //
  //    BeginVerticalLayout();
  //    // chat body view
  //    EndVerticalLayout();
  //
  //  EndHorizontalLayout();
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