solution "cdmath"
	configurations { "Debug", "Release" }

project "cdmath"
	kind "ConsoleApp"
	language "C++"
	cppdialect "c++17"
	targetdir "%{cfg.buildcfg}"

	files {
		"../**.h",
		"../**.cpp",
		"./main.cpp",
		"premake5.lua"
	}

	includedirs {
		"../include"
	}

	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:Release"
		defines { "NDEBUG" }
		symbols "On"
		optimize "On"
