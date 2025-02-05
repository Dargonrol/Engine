project (CoreName)
   kind "SharedLib"
   language "C++"
   cppdialect "C++20"
   targetdir "bin/%{cfg.buildcfg}"
   staticruntime "Off"
   
   pchheader "pch.h"
   pchsource "src/pch.cpp"

   files { "src/**.h", "src/**.cpp" }

   includedirs
   {
      "src",
	  -- additional libs
	  ("../" .. CoreName .. "/Vendor/spdlog/include"),
	  ("../" .. CoreName .. "/Vendor/bgfx/include"),
	  ("../" .. CoreName .. "/Vendor/Eigen/Eigen")
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

	filter "system:windows"
			postbuildcommands
				{
					('{COPY} "%{wks.location}/bin/%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}/' .. CoreName .. '/' .. CoreName .. '.dll" ../bin/' .. OutputDir .. "/%{prj.name}")
				}
		   