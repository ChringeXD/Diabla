workspace "Diabla"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"





project "Diabla"
	location "Diabla"
	kind "SharedLib"
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
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"DB_PLATFORM_WINDOWS",
			"DB_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

		buildoptions "/utf-8"

	filter "configurations:Debug"
		defines "DB_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "DB_RELEASE"
		optimize "On"

	filter "configurations:Dist"
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
		"Diabla/vendor/spdlog/include",
		"Diabla/src"
	}

	links
	{
		"Diabla"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.22621.0"

		defines
		{
			"DB_PLATFORM_WINDOWS"
		}

		buildoptions "/utf-8"

	filter "configurations:Debug"
		defines "DB_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "DB_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "DB_DIST"
		optimize "On"