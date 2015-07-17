package;

import openfl.display.Stage;
import openfl.display.StageAlign;
import openfl.display.StageScaleMode;
import openfl.display.StageQuality;
import openfl.display.Bitmap;
import openfl.display.BitmapData;
import openfl.display.Sprite;
import openfl.Assets;

class Main extends Sprite {
	
	public function new () {
		
		super();
		trace(NativeCamera.DeviceIdentifier());
		NativeCamera.Initialize();
	}
	
	
}