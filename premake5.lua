workspace "Diabla"
	architecture "x64"

	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)

IncludeDir = {}
IncludeDir["GLAD"] = "Diabla/vendor/GLAD/include"
IncludeDir["GLFW"] = "Diabla/vendor/GLFW/include"
IncludeDir["ImGui"] = "Diabla/vendor/imgui"

include "Diabla/vendor/GLAD"
include "Diabla/vendor/GLFW"
include "Diabla/vendor/imgui"

project "Diabla"
	location "Diabla"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "dbpch.h"
	pchsource "Diabla/src/dbpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLAD}",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.ImGui}"
	}

	links
	{
		"GLAD",
		"GLFW",
		"ImGui",
		"opengl32.lib",
		"dwmapi.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "off"
		systemversion "latest"

		defines
		{
			"DB_PLATFORM_WINDOWS",
			"DB_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox\"")
		}

		buildoptions "/utf-8"

	filter "configurations:Debug"
		runtime "Debug"
		defines 
		{
			"DB_DEBUG",
			"DB_ENABLE_ASSERTS"
		}
		symbols "On"

	filter "configurations:Release"
		runtime "Release"
		defines "DB_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		runtime "Release"
		defines "DB_DIST"
		optimize "On"





project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Diabla/src",
		"Diabla/vendor/spdlog/include"
	}

	links
	{
		"Diabla"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "off"
		systemversion "latest"

		defines
		{
			"DB_PLATFORM_WINDOWS"
		}

		buildoptions "/utf-8"

	filter "configurations:Debug"
		runtime "Debug"
		defines 
		{
			"DB_DEBUG",
			"DB_ENABLE_ASSERTS"
		}
		symbols "On"

	filter "configurations:Release"
		runtime "Release"
		defines "DB_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DB_DIST"
		optimize "On"