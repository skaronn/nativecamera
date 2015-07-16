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
	
	
	public static function sampleMethod (inputValue:Int):Int {
		
		#if (android && openfl)
		
		var resultJNI = nativecamera_sample_method_jni(inputValue);
		var resultNative = nativecamera_sample_method(inputValue);
		
		if (resultJNI != resultNative) {
			
			throw "Fuzzy math!";
			
		}
		
		return resultNative;
		
		#else
		
		return nativecamera_sample_method(inputValue);
		
		#end
		
	}
	
	
	private static var nativecamera_sample_method = Lib.load ("nativecamera", "nativecamera_sample_method", 1);
	
	#if (android && openfl)
	private static var nativecamera_sample_method_jni = JNI.createStaticMethod ("org.haxe.extension.NativeCamera", "sampleMethod", "(I)I");
	#end
	
	
}