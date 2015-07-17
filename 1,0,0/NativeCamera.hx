package;

#if cpp
import cpp.Lib;
#elseif neko
import neko.Lib;
#end

#if (android && openfl)
import openfl.utils.JNI;
#end


class NativeCamera {
	
	/**
	 * 
	 */
	public static function DeviceIdentifier() : String
    {
		var identifier : String = "";
		#if flash
		identifier = Std.string(flash.media.Camera.names[0]);
		#elseif android
		identifier = Std.string(JNI.createStaticMethod("org.haxe.extension.NativeCamera", "getDeviceIdentifier", "()Ljava/lang/String;"));
		#elseif windows
		var device_number = Lib.load("nativecamera", "nativecamera_device_identifier", 0);
		identifier = Std.string(device_number);
		#end
		return identifier;
	}
	
	/**
	 * 
	 */
	public static function Initialize() : Void
    {
		#if flash
		var mc : openfl.display.MovieClip ;
		var rawvideo : flash.media.Video ;
		var cam:flash.media.Camera = flash.media.Camera.getCamera();
		cam.setMode(640, 480, 30);
		cam.setQuality(0, 100);

		mc = flash.Lib.current;
		rawvideo = new flash.media.Video(cam.width, cam.height);
		rawvideo.attachCamera(cam);

		if (cam != null) {
			var videoContainer:openfl.display.MovieClip = new openfl.display.MovieClip();
			videoContainer.addChild(rawvideo);
			mc.addChild(videoContainer);
			trace("w=" + cam.width + ", h=" + cam.height + ", fps=" + cam.fps);
		}
		else {
			trace("No Camera") ;
		}		
		#end
	}
	
	/**
	 * 
	 */
	public static function TakePhoto() : Void
    {
		
	}
	
	/**
	 * 
	 */
	public static function TakeVideo() : Void
    {
		
	}
	
}