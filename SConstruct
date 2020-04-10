print('..Building App\n')

#TODO: find default paths
defaultLinuxPathToBoostHeaders = '/usr/include/boost/'
defaultWinPathToBoostHeaders = ''
defaultLinuxPathToSFMLHeaders = '/usr/include/SFML/'
defaultWinPathToSFMLLibrary = ''

pathToBoostHeaders = '#libraries/boost_1_72_0/'
pathToSFMLHeaders = '#libraries/SFML-2.5.1/include'
pathToSFMLLibraries = '#libraries/SFML-2.5.1/lib/'
pathToBox2DHeaders = '#libraries/box2d-master/include/'
pathToBox2DLibrary = '#libraries/box2d-master/build/src/'

#TODO: Windows showing random junk symbols "are not recognized as a command" in the Environment block
env_base = Environment(
    CC = 'g++',
    CCFLAGS = '-O2 -Wall',
    SCONS_CXX_STANDARD='c++11',
    CPPPATH = [
        '#include',
        '#include/main/utility',
        pathToSFMLHeaders,
        pathToBoostHeaders,
        pathToBox2DHeaders
        ],
    LIBPATH = [
        pathToSFMLLibraries,
        pathToBox2DLibrary
        ]
)

binFolder = '#bin/'
pathToUtility = '#include/main/utility/'
libraryPath = binFolder + 'libs/'
programName = 'hello'
programPath = '#'


#check for essential libraries
if not env_base.GetOption('clean'):
    import sys
    import subprocess
    conf = Configure(env_base)

    print '..Checking for libraries:\n'

#TODO: exit on installation error

    if sys.platform.startswith('linux'):

        if not conf.CheckCXXHeader(defaultLinuxPathToBoostHeaders + 'shared_ptr.hpp') and not conf.CheckCXXHeader('boost/shared_ptr.hpp'):
            print 'Boost not found\n'
            subprocess.call(['./BoostLinux.sh'], shell=True, cwd = 'scripts')
        else:
            print 'Boost found\n'

        if not conf.CheckCXXHeader(defaultLinuxPathToSFMLHeaders + 'Graphics.hpp') and not conf.CheckCXXHeader('SFML/Graphics.hpp'):
        #if not conf.CheckLib('sfml-graphics'):
            print 'SFML not found\n'
            subprocess.call(['./SFMLLinux.sh'], shell=True, cwd = 'scripts')
        else:
            print 'SFML found\n'

        if not conf.CheckLib('box2d'):
            print 'Box2D not found\n'
            subprocess.call(['./Box2DLinux.sh'], shell=True, cwd = 'scripts')
        else:
            print 'Box2D found\n'
    
    elif sys.platform.startswith('win'):
        
        #TODO: Windows Boost checking

        #TODO: Windows SFML checking

        
        if not conf.CheckLib('box2d'):
            print 'Box2D not found\n'
            subprocess.call(['powershell.exe', '.\Box2DWin.ps1'], shell=True, cwd = 'scripts') #TODO: box2d.sln error
        else:
            print 'Box2D found\n'


    else:
        print 'Unsupported OS. Exiting.'
        Exit(1)



#Exit(1)

print('..Building Targets\n')
#build in separate directories
SConscript(
    'source/graphic_library_facade/SConscript', 
    exports=['env_base', 'binFolder', 'pathToUtility', 'libraryPath'], 
    variant_dir = binFolder + 'graphic_library_facade', 
    duplicate=0
    )

SConscript(
    'source/main/program_events/SConscript', 
    exports=['env_base', 'binFolder', 'pathToUtility', 'libraryPath'], 
    variant_dir = binFolder + 'main/program_events', 
    duplicate=0
    )

SConscript(
    'source/main/screen/SConscript', 
    exports=['env_base', 'binFolder', 'pathToUtility', 'libraryPath'], 
    variant_dir = binFolder + 'main/screen', 
    duplicate=0
    )

SConscript(
    'source/main/drawing/SConscript', 
    exports=['env_base', 'binFolder', 'pathToUtility', 'libraryPath'], 
    variant_dir = binFolder + 'main/drawing', 
    duplicate=0
    )


#print(Glob(['*.cpp', '../graphic_library_facade/*.o', 'program_events/*.o']))

#env.Program('hello', Glob(['*.cpp', '../graphic_library_facade/*.o', 'program_events/*.o']))
#env.Program(target = 'hello', source = ['main.cpp', 'renderLoop.cpp', '../graphic_library_facade/graphicLibraryFacade.o', 'program_events/basicEvents.o', 'program_events/eventManager.o', 'program_events/eventInterface.h'])
#['main.cpp', 'renderLoop.cpp', '../graphic_library_facade/graphicLibraryFacade.o']

#hello = env.Program(target = 'hello', source = ['source/main/main.cpp', 'source/main/renderLoop.cpp', 'build/graphic_library_facade/graphicLibraryFacade.o'])

SConscript(
    'source/main/SConscript', 
    exports = ['env_base', 'libraryPath', 'programName', 'programPath', 'binFolder', 'pathToBox2DHeaders'], 
    variant_dir= binFolder + 'main', 
    duplicate=0
    )

#the install option
#env.Install('usr/bin/scontest', hello)
#env.Alias('install', 'usr/bin/scontest')