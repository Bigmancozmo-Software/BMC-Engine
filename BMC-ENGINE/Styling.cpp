#include "Styling.h"

void Styler::setToDefault()
{
	ImGuiStyle* style = &ImGui::GetStyle();

	style->WindowRounding = 7;
	style->ChildRounding = 7;
	style->FrameRounding = 3;
	style->PopupRounding = 7;
	style->TabRounding = 3;
	style->GrabRounding = 3;

	style->WindowPadding = ImVec2(10, 10);

	style->ScrollbarSize = 11;

	style->TableAngledHeadersAngle = 40;

	style->WindowBorderSize = 0;
	style->FrameBorderSize = 0;
	style->PopupBorderSize = 0;
}
