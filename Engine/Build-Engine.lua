project (CoreName)
   kind "StaticLib"
   language "C++"
   cppdialect "C++20"
   targetdir "bin/%{cfg.buildcfg}"
   staticruntime "on"
   
   pchheader "pch.h"
   pchsource "src/pch.cpp"

   files { "src/**.h", "src/**.cpp" }

   includedirs
   {
      "src",
	  -- additional libs
	  "../Vendor/spdlog/include",
	  "../Vendor/bgfx/include",
	  "../Vendor/Eigen"
   }

   targetdir ("../bin/" .. OutputDir .. "/%{prj.name}")
   objdir ("../bin/Intermediates/" .. OutputDir .. "/%{prj.name}")

	filter "system:windows"
		systemversion "latest"
		defines { "CORE_PLATFORM_WINDOWS", "CORE_BUILD_DLL" }
		buildoptions { "/utf-8" }
	  
		filter "architecture:x86"
			-- libdirs { "../Vendor/bin/SDL/Windows/32" }
			
			
		filter "architecture:x86_64"
			-- libdirs { "../Vendor/bin/SDL/Windows/64" }
			
		filter "architecture:ARM64"
			-- libdirs { "../Vendor/bin/SDL/arm64" }
			
	filter "system:linux"
        pic "On"
        defines { "LINUX" }

        -- libdirs { "../Vendor/bin/SDL/Unix" }
        links {"dl", "pthread" }

   filter "configurations:Debug"
       defines { "DEBUG" }
       runtime "Debug"
       symbols "On"

   filter "configurations:Release"
       defines { "RELEASE" }
       runtime "Release"
       optimize "On"
       symbols "On"

   filter "configurations:Dist"
       defines { "DIST" }
       runtime "Release"
       optimize "On"
       symbols "Off"