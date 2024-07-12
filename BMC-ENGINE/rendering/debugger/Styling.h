#ifndef STYLING_H
#define STYLING_H

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

/// 
/// Styles ImGui windows.
/// 
class Styler {
public:
	/// 
	/// Resets the ImGui style to the program's default.
	/// 
	static void setToDefault();
};

#endif // STYLING_H