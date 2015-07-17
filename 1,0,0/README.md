NativeCamera
=======

### Library for native camera handling using HaXe on following platforms :

 * Android
 * Flash
 * Windows
 * iOS
 
### Fonctionalities :

 * Returns native camera identifier
 * Initialize native camera
 * Take photo
	- Take photos from a mobile device's camera and receive the byte data 
	- Triggers the built-in camera in iOS and Android, or the Photo Library picker
	  in the iOS Simulator. 
	- Returns the captured photo to Haxe as JPEG byte data via a `CameraEvent` on the stage.
	- Simulates a camera event from provided `BitmapData` for non-mobile platforms.
	- Allows placing a `BitmapData` overlay over the built-in camera display.
	- *TODO*: Implement overlay in Android.
 * Take video
 
Installation
------------

    git clone https://github.com/skaronn/nativecamera
    lime rebuild nativecamera flash
	lime rebuild nativecamera windows
	lime rebuild nativecamera ios
    lime rebuild nativecamera android
	
### project.xml

    <include path="/path/to/nativecamera" />

	
Sample code implementation
------------
    
    class Main extends Sprite
    {
        public function new()
        {
            super();

            NativeCamera.initialize();

            ...
        }
    }


References
----------------

- [https://github.com/josuigoa/CameraMic](https://github.com/josuigoa/CameraMic)
- [https://github.com/hopewise/HardDiskSerialNumberExtension](https://github.com/hopewise/HardDiskSerialNumberExtension)
- [https://github.com/bazzisoft-openfl-extensions/camera](https://github.com/bazzisoft-openfl-extensions/camera)
- [http://adoptioncurve.net/archives/2012/04/using-the-camer-of-ios-simulators/](http://adoptioncurve.net/archives/2012/04/using-the-camer-of-ios-simulators/)
- [http://vocaro.com/trevor/blog/2009/10/12/resize-a-uiimage-the-right-way/](http://vocaro.com/trevor/blog/2009/10/12/resize-a-uiimage-the-right-way/)

###License

The MIT License (MIT) - [LICENSE.md](LICENSE.md)

Copyright &copy; 2015

Author: Marcus Skaronn

WORK IN PROGRESS !!!
----------------