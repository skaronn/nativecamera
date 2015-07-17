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
	
	private static var cameraDeviceID = Dynamic;
	private static var cameraVideoData = Dynamic;
	
	/**
	 * 
	 */
	public static function DeviceIdentifier() : String
    {
		var identifier : String = "";
		#if flash
		identifier = Std.string(flash.media.Camera.names[0]);
		#elseif android
		cameraDeviceID = JNI.createStaticMethod("org.haxe.extension.NativeCamera", "getDeviceIdentifier", "()Ljava/lang/String;");
		#elseif (windows || cpp)
		cameraDeviceID = Lib.load("nativecamera", "nativecamera_device_identifier", 0);
		#end
		identifier = Std.string(cameraDeviceID);
		return identifier;
	}
	
	/**
	 * 
	 */
	public static function Initialize() : String
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
			trace("No Camera");
		}
		#elseif android
		cameraVideoData = JNI.createStaticMethod("org.haxe.extension.NativeCamera", "initialize", "()Ljava/lang/String;"));		
		#elseif (windows || cpp)
		cameraVideoData = Lib.load("nativecamera", "nativecamera_initialize", 0);
		#end
		return Std.string(cameraVideoData);
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