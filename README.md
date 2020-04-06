gro
===

The gro bacterial micro-colony growth specification and simulation software.

Documentation
=============

The latest documentation for gro is available from

  http://depts.washington.edu/soslab/gro/docview.html

Compiling
=========

MacOS
-----
You will need the following packages in order to compile gro:

* CCL: https://github.com/klavinslab/ccl
* Chipmunk 5.3.5: https://chipmunk-physics.net/release/Chipmunk-5.x/
* XCode

Once you have these pre-requisties, you can install `gro` by running
`qmake` and telling it where to find the ccl and chipmunk source
directories (which should also have the compiled library files).

    qmake CCL=<cclpath> CHIPMUNK=<chipmunkpath>
    make

This will create directory `gro.app` that can run using the command

    open gro.app

Linux
-----
You will need the following packages in order to compile gro:

* CCL: https://github.com/klavinslab/ccl
* Chipmunk 5.3.5: https://chipmunk-physics.net/release/Chipmunk-5.x/
* Linux build tools (via apt): build-essential, flex, bison, libreadline-dev
* OpenGL: freeglut3-dev

Once you have these pre-requisties, you can install `gro` by running
`qmake` and telling it where to find the ccl and chipmunk source
directories (which should also have the compiled library files).

    qmake CCL=<cclpath> CHIPMUNK=<chipmunkpath>
    make

The file `useful/chipmunk.gro` in the main `gro` directory is
available to allow compilation of chipmunk via `qmake`.  To use it,
copy `useful/chipmunk.gro` to the `chipmunk` main source directory and
run `qmake` then `make`.

If you are running `gro` on a remote host and you are using X11
fowarding back mac to a Mac, please note the following:

* Run ssh -Y (not -X) to forward the X11 connection

* If you have font rendering problems, try running `xterm` and then
  run `gro` from the `xterm` window.

Windows
-------

Running `gro`
=============

The `gro` application should open a window from which you can load and
run `gro programs`.  The following environment variables can be used
to help gro find files that it needs:

    GROHOME	Initial directory for opening `gro` files
    GROPATH	Colon-separate list of directories to search for include files
    
Apple Paths
===========

If you are on a Mac you may have discovered an issue with gro not
starting properly because of an old directory structure issue. David
Soloviechik uses this AppleScript to solve that problem

    tell application "Finder"
    	set current_path to container of (path to me) as alias
    end tell
    set dir to (POSIX path of current_path)
    do shell script "cd \"" & dir & "\" && gro.app/Contents/MacOS/gro > /dev/null 2>&1 &"

To use this script, put it in a file called `run_gro.scpt` within the
gro directory and then at the command line run

    > osascript run_gro.scpt
    
    
