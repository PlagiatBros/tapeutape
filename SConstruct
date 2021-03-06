# ENVIRONMENT
env = Environment(CPPFLAGS=' -I/usr/include/libxml2',LIBS=['asound','pthread','xml2','sndfile','samplerate','jack'])

# SOURCE FILES
base = Glob('src/base/*.cpp')
audio = Glob('src/audio/*.cpp')
midi = Glob('src/midi/*.cpp')
ui = Glob('src/ui/*.cpp')
sources = base+audio+midi

# LANGUAGE
optlang = ARGUMENTS.get('lang','en')

#  CONFIGURE 
if not env.GetOption('clean') and not 'install' in COMMAND_LINE_TARGETS and not env.GetOption('help'):
	# CHECK DEPENDENCIES
	conf = Configure(env)
	missing=''
	######## GCC
	f = FindFile('g++', ['/usr/bin', '/usr/local/bin'])
	if f:
		print 'Checking for g++...yes'
	else:
		missing+='g++\n'
		print 'Checking for g++...no'
	######## JACK
	if not conf.CheckCHeader('jack/jack.h'):
		missing+='jack\n'
	######## ALSA
	if not conf.CheckCHeader('alsa/asoundlib.h'):
		missing+='alsa\n'
	######## SNDFILE
	if not conf.CheckCHeader('sndfile.h'):
		missing+='sndfile\n'
	######## SAMPLERATE
	if not conf.CheckCHeader('samplerate.h'):
		missing+='samplerate\n'
	######## XML2
	if not conf.CheckCHeader('libxml2/libxml/parser.h'):
		missing+='libxml2'
	# OPTIONS
	#######	GUI
	optgui = ARGUMENTS.get('gui', 1)
	if (optgui == 1):
		if not conf.CheckCXXHeader('FL/Fl.H'):
			missing+='fltk\n'
		else:
			sources+=ui
			env.ParseConfig('fltk-config --libs --cxxflags --ldflags')
			env.Append(CPPFLAGS = ' -DWITH_GUI ')
	env = conf.Finish()

	#IF SOMETHING WAS MISSING
	if(missing!=''):
		if(optlang=='fr'):
			print '\nLes dependances suivantes sont manquantes:\n'
			print missing
			print '\n'
			print """Merci de les installer (paquetages -dev ou -devel) puis de re-entrer la commande 'scons lang=fr'
				"""
		else:
			print '\nThe following dependencies are missing:\n'
			print missing
			print '\n'
			print """Please install them (packages -dev or -devel) and re-type 'scons'
				"""
		Exit(1)
	
# BUILD
if not 'install' in COMMAND_LINE_TARGETS:
	tapeutape = env.Program('tapeutape',sources)
	Clean(tapeutape,'.sconsign.dblite')
	if(optlang=='fr'):
		env['CXXCOMSTR'] = "Compilation de $TARGET"
		env['LINKCOMSTR'] = "Assemblage de $TARGET"
	else:
		env['CXXCOMSTR'] = "Compiling $TARGET"
		env['LINKCOMSTR'] = "Linking $TARGET"

# INSTALL
bin = env.Install('/usr/local/bin', 'tapeutape')
desktop = env.Install('/usr/local/share/applications', 'data/tapeutape.desktop')
icon = env.Install('/usr/local/share/pixmaps', 'data/tapeutape.png')
env.Alias('install', [bin,desktop,icon])

# HELP
if (optlang=='fr'):
	Help("""
		Bienvenue dans le programme d'installation de Tapeutape

		Commencez par entrer la commande 'scons lang=fr' pour compiler Tapeutape 
			ajoutez l'option 'gui=0' pour compiler la version ligne de commande

		Si tout se passe bien, entrez 'scons install' en tant qu'administrateur 
		pour installer Tapeutape dans /usr/local/

		Si vous voulez nettoyer la compilation, entrez 'scons -c'
		Si vous voulez desinstaller Tapeutape, entrez 'scons -c install'
	     """)
else:
	Help("""
		Welcome to Tapeutape's Installation Program

		Please type 'scons' to build Tapeutape 
			add the option 'gui=0' to build the command line version
			add the option 'lang=fr' to display the build instructions in french

		If everything went good, type 'scons install' as root 
		to install Tapeutape in /usr/local/

		If you want to clean the build, type 'scons -c'
		If you want to uninstall Tapeutape, type 'scons -c install'
	     """)
	

