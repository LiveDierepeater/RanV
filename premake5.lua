workspace "RanV"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "RanV/vendor/GLFW/include"

include "RanV/vendor/GLFW"

project "RanV"
	location "RanV"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "ranvpch.h"
	pchsource "RanV/src/ranvpch.cpp"
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"RANV_PLATFORM_WINDOWS",
			"RANV_BUILD_DLL",
			"RANV_ENABLE_ASSERTS"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "RANV_DEBUG"
		symbols "On"
		buildoptions
		{
			"/utf-8",
			"/MDd"
		}

	filter "configurations:Release"
		defines "RANV_RELEASE"
		optimize "On"
		buildoptions
		{
			"/utf-8",
			"/MD"
		}

	filter "configurations:Dist"
		defines "RANV_DIST"
		optimize "On"
		buildoptions "/utf-8"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	buildoptions "/utf-8"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"RanV/vendor/spdlog/include",
		"RanV/src"
	}

	links
	{
		"RanV"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"RANV_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "RANV_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "RANV_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "RANV_DIST"
		optimize "On"