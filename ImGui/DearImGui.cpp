#include "DearImGui.h"

void Kyuubi::DearImGui::Initialize(SDL_Window* window, SDL_Renderer* renderer) {
	KYEngine("Initializing ImGui");
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	

	ImGui::StyleColorsDark();

	ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
	ImGui_ImplSDLRenderer2_Init(renderer);

	io.Fonts->AddFontDefault();
}

bool Kyuubi::DearImGui::ProcessEvent(SDL_Event* event) {
		ImGui_ImplSDL2_ProcessEvent(event);

		if (ImGui::GetIO().WantCaptureMouse) {
			// ImGui is capturing mouse events, so we consume them here
			if (event->type == SDL_MOUSEBUTTONDOWN || event->type == SDL_MOUSEBUTTONUP) {
				// Consume mouse button events
				return true;
			}
			else if (event->type == SDL_MOUSEMOTION && ImGui::IsMouseDragging(0)) {
				// Consume mouse motion events if dragging in ImGui
				return true;
			}
		}

		// Check if ImGui wants to capture keyboard inputs
		if (ImGui::GetIO().WantCaptureKeyboard) {
			// ImGui is capturing keyboard inputs, so we consume them here
			if (event->type == SDL_KEYDOWN || event->type == SDL_KEYUP) {
				// Consume keyboard events
				return true;
			}
		}

		// If ImGui does not want to capture the event, allow it to propagate
		return false;
}

void Kyuubi::ImGuiWindow::NewFrame() {
	ImGui_ImplSDLRenderer2_NewFrame();
	ImGui_ImplSDL2_NewFrame();
	ImGui::NewFrame();

	bool createdNewWindow = true;
	ImGui::Begin("New Window");

	ImGui::Text("This is a new window!");
	ImGui::Checkbox("Created new window", &createdNewWindow);

	ImGui::ShowDemoWindow();

	ImGui::End();
}
