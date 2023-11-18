#include "Window.hpp"
#include <iostream>
#include "config/MenuConfig.hpp"

Window::Window(const std::string &name, int width, int height) : width(width), height(height) {
  if( !glfwInit() ){
    throw std::invalid_argument("Failed to initialize GLFW");
	}

  window = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);
	if( window == nullptr ){
		glfwTerminate();
    throw std::invalid_argument("Failed to open GLFW window");
	}

	glfwMakeContextCurrent(window);

	ImGui::CreateContext();

	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init("#version 330");

	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, WIDTH - 1, HEIGHT - 1, 0, 0, 1);
	glMatrixMode(GL_MODELVIEW);
}

void Window::startMainLoop() {
  do{		
		glfwPollEvents();

    drawImGui();

    draw();

		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		glfwSwapBuffers(window);
	} 
	while(glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwDestroyWindow(window);
	glfwTerminate();
}

void Window::draw() {
  glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
  glClear( GL_COLOR_BUFFER_BIT );
}

void Window::drawImGui() {
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();

  ImGui::NewFrame();

  auto windowPos = ImVec2(0, 0);

  ImGui::SetNextWindowSize(getMenuSize(), ImGuiCond_Always);
  ImGui::SetNextWindowPos(windowPos, ImGuiCond_Always);

  ImGui::Begin("ImGui Window", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoTitleBar);
  ImGui::SetWindowFontScale(FONT_SCALE_MILTIPLICATOR);

  ImGuiStyle& style = ImGui::GetStyle();
  style.FrameRounding = 4.0f;
  style.Colors[ImGuiCol_WindowBg] = ImVec4(0.9f, 0.9f, 0.9f, 0.9f);
  
  style.Colors[ImGuiCol_Header] = ImVec4(0.3f, 0.3f, 0.6f, 1.0f);
  style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.4f, 0.4f, 0.8f, 1.0f);
  style.Colors[ImGuiCol_Text] = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
  style.Colors[ImGuiCol_PopupBg] = ImVec4(0.8f, 0.8f, 0.8f, 0.8f);  // Измените цвет по вашему вкусу
  style.ItemInnerSpacing = ImVec2(10, 10);

  drawMenu();


  ImGui::End();

  //drawRightClickMenu

  ImGui::Render();
  ImGui::EndFrame();
}

void Window::drawMenu() {
  ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.4f, 0.4f, 0.8f, 1.0f));
  ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.5f, 0.5f, 0.9f, 1.0f));
  ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.3f, 0.3f, 0.7f, 1.0f));

  ImGui::Separator();

  for (const auto &[menuName, menuElements] : selectedModeConfig) {		
		ImGui::SetWindowFontScale(FONT_SCALE_MILTIPLICATOR);
    std::string menuLabel = "\n" + menuName + "\n\n";
		if (ImGui::BeginMenu(menuLabel.c_str())) {
			for (const auto &[submenuName, submenuElement] : menuElements) {
        std::string submenuLabel = submenuName;
				if (ImGui::Button(submenuLabel.c_str(), ImVec2(getMenuSize().x * 1.5, 50))) {
					std::cout << "Bruh" << std::endl; //TODO: call draw method
				}
			}
			ImGui::EndMenu();
		}
    ImGui::Separator();
	}
  ImGui::PopStyleColor(3);
}

ImVec2 Window::getMenuSize() {
  return ImVec2(getWidth() / 10, getHeight());
}


int Window::getWidth() {
  glfwGetWindowSize(window, &width, &height);
  return width;
}

int Window::getHeight() {
  glfwGetWindowSize(window, &width, &height);
  return height;
}
