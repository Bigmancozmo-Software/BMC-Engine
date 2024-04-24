#include "DebugUtil.h"

DebugUtil::DebugUtil(GLFWwindow* window)
{
	this->window = window;
}

void DebugUtil::draw()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	ImGui::Begin("Debugging Tools");
	ImGui::SetWindowCollapsed(true, ImGuiCond_Once);
	ImGui::SetWindowPos(ImVec2(10, 10), ImGuiCond_Once);
	ImGui::Text("These are the DEBUGGING TOOLS.\nMake sure you know what you're doing!");
	ImGui::Checkbox("Antialiasing", &(DebugSettings::useAntiAliasing));
	ImGui::End();

	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	processVars();
}

void DebugUtil::processVars()
{
	if (DebugSettings::useAntiAliasing)
	{
		glEnable(GL_MULTISAMPLE);
	}
	else { glDisable(GL_MULTISAMPLE); }
}
