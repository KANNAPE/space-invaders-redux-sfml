workspace "SpaceInvadersRedux"
	configurations { "Debug", "Release" }
	platforms { "x64" }
	system "Windows"
	architecture "x64"
	location "../.."

project "SpaceInvadersRedux"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++17"
   location ".."

   files { "../src/**.h", "../src/**.cpp" }
   
   includedirs { "../include", "../src" }
   libdirs { "../lib" }

   filter "configurations:Debug"
	  targetdir "../../x64/Debug"
      defines { "DEBUG" }
      symbols "On"
	  links { "sfml-audio-d", "sfml-graphics-d", "sfml-network-d", "sfml-system-d", "sfml-window-d" }

   filter "configurations:Release"
	  targetdir "../../x64/Release"
      optimize "On"
	  links { "sfml-audio", "sfml-graphics", "sfml-network", "sfml-system", "sfml-window" }