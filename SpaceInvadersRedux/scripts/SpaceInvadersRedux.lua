workspace "SpaceInvadersRedux"
	configurations { "Debug", "Release" }
	location "../.."

project "SpaceInvadersRedux"
   kind "ConsoleApp"
   language "C++"
   location ".."

   files { "../src/**.h", "../src/**.cpp" }
   
   includedirs { "../include" }
   libdirs { "../lib" }

   filter "configurations:Debug"
	  targetdir "x64/Debug"
      defines { "DEBUG" }
      symbols "On"
	  links { "sfml-audio-d", "sfml-graphics-d", "sfml-network-d", "sfml-system-d", "sfml-window-d" }

   filter "configurations:Release"
	  targetdir "x64/Release"
      optimize "On"
	  links { "sfml-audio", "sfml-graphics", "sfml-network", "sfml-system", "sfml-window" }