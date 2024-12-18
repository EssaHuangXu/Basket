workspace "Basket"
  architecture  "x64"
  configurations { "Debug","Release","Dist" }
  startproject "Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Basket"
  location "Basket"
  kind "SharedLib"
  language "C++"
  targetdir ("bin/" .. outputdir .. "/%{prj.name}")
  objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
  files {"%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp"}
  includedirs { "%{prj.name}/vendor/spdlog/include" }
  buildoptions { "/utf-8" }

  filter "system:windows"
    cppdialect "C++17"
    staticruntime "On"
    systemversion "10.0"
    defines { "BK_PLATFORM_WINDOWS", "BK_BUILD_DLL" }
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

  filter "configurations:Debug"
    defines "BK_DEBUG"
    symbols "On"
  filter "configurations:Release"
    defines "BK_RELEASE"
    optimize "On"
  filter "configurations:Dist"
    defines "BK_DIST"
    optimize "On"


project "Sandbox"
  location "Sandbox"
  kind "ConsoleApp"
  language "C++"
  targetdir ("bin/" .. outputdir .. "/%{prj.name}")
  objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
  files { "%{prj.name}/src/**.h", "%{prj.name}/src/**.cpp" }
  includedirs { "Basket/vendor/spdlog/include", "Basket/src" }
  links { "Basket" }
  buildoptions { "/utf-8" }

  filter "system:windows"
    cppdialect "C++17"
    staticruntime "On"
    systemversion "10.0"
    defines { "BK_PLATFORM_WINDOWS" }

  filter "configurations:Debug"
    defines "BK_DEBUG"
    symbols "On"
  filter "configurations:Release"
    defines "BK_RELEASE"
    optimize "On"
  filter "configurations:Dist"
    defines "BK_DIST"
    optimize "On"