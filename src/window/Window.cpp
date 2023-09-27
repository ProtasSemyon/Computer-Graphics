#include <iostream>

#include "Window.hpp"
#include "config/MenuConfig.hpp"
#include <iostream>


Window::Window(const std::string &name, int width, int height) : width(width), height(height){
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

void OsOpenInShell(const char* path)
{
#ifdef _WIN32
    // Note: executable path must use backslashes!
    ::ShellExecuteA(NULL, "open", path, NULL, NULL, SW_SHOWDEFAULT);
#else
#if __APPLE__
    const char* open_executable = "open";
#else
    const char* open_executable = "xdg-open";
#endif
    char command[256];
    snprintf(command, 256, "%s \"%s\"", open_executable, path);
    system(command);
#endif
}

void Window::startMainLoop() {
  do{		
		glfwPollEvents();
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();

		ImGui::NewFrame();

		// Check for right-click to open the pop-up menu
		
		if (ImGui::IsKeyPressed(ImGuiKey_MouseRight)) {
			ImGui::OpenPopup("ModeMenu");
		}

		if (ImGui::BeginPopup("ModeMenu")) {
			isMenuOpened = true;
			drawMenu();
			ImGui::EndPopup();
		} else {
			isMenuOpened = false;
		}

		if (open_about) {
			ImGui::OpenPopup("About");
		}
		if (ImGui::BeginPopup("About")){
			ImGui::SetWindowFontScale(width / FONT_SCALE_MILTIPLICATOR);

			ImGui::Text("Protas Semyon");
			if (ImGui::Button("GitHub: https://github.com/ProtasSemyon/Computer-Graphics")){
				OsOpenInShell("https://github.com/ProtasSemyon/Computer-Graphics");
				open_about = false;
			}
			ImGui::EndPopup();
		}

		// Render your main application here

		// Rendering
		ImGui::Render();

		ImGui::EndFrame();


		draw();

		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		glfwSwapBuffers(window);
	} 
	while(!closeCondition());

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwDestroyWindow(window);
	glfwTerminate();
}

bool Window::closeCondition() {
  return glfwGetKey(window, GLFW_KEY_ESCAPE ) == GLFW_PRESS || glfwWindowShouldClose(window) != 0;
}

void Window::draw() const {
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
  glClear( GL_COLOR_BUFFER_BIT );
	
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	DrawableObjectPool::getInstance().draw();
	if (mode) {
		mode->draw();
	}
}

void Window::setMode(IMode* newMode) {
	mode = newMode;
	mode->setWindow(this);
}

void Window::drawMenu() {
	for (const auto &[menuName, menuElements] : menuConfig) {		
		ImGui::SetWindowFontScale(width / FONT_SCALE_MILTIPLICATOR);
		if (ImGui::BeginMenu(menuName.c_str())) {
			for (const auto &[submenuName, submenuElement] : menuElements) {
				if (ImGui::MenuItem(submenuName.c_str())) {
					setMode(submenuElement.get());
				}
			}
			ImGui::EndMenu();
		}
	}

	ImGui::Separator();
	if (ImGui::MenuItem("Debug")) {
		IMode::changeDebugState();
	}

	ImGui::Separator();
	if (ImGui::MenuItem("About")) {
		open_about = true;
	}
}

GLFWwindow* Window::getWindow() const {
	return window;
}

bool Window::getIsMenuOpened() const {
	return isMenuOpened;
}

int Window::getWidth() const {
	return width;
}

int Window::getHeight() const {
	return height;
}
