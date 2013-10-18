var _framerate = require('tools/framerate.js');
var _gl = require('opengl');
var _global = require('framework/global.js');

var mCamera = _global.mCamera;
var mRenderContext = _global.mRenderContext;

var _geometry = require('core/glm.js');
var _glm = _geometry.glm;
var _v3 = _geometry.vec3f;
var _inherit = require('core/inherit.js');

var firstInit = true;
function Game() {
}
var game = new Game();
game.pause = function () {
}
game.resume = function () {
    _global.updateContext.reset();
}

var mCount = 0;
game.render = {
    onSurfaceCreated: function (width, height) {
        _gl.clearColor(1, 1, 1, 0);

        _gl.enable(_gl.BLEND);
        _gl.blendFunc(_gl.ONE, _gl.ONE_MINUS_SRC_ALPHA);
        console.log('game.onSurfaceCreated');

        _gl.disable(_gl.DEPTH_TEST);
        _gl.disable(_gl.STENCIL_TEST);
        _gl.disable(_gl.SCISSOR_TEST);

        mCamera.lookAt([0, 0, 10], [0, 0, 0], [0, 1, 0]).ortho(0, width, 0, height, 9, 11);
        mRenderContext.onChange();
        mCamera.setViewport(width, height);
        mCamera.viewport();

        if (firstInit) {
			_global.registerScene(require('scenes/cover.js').newInstance('cover', width, height));
            //_global.registerScene(require('scenes/game.js').newInstance('game', width, height));
            firstInit = false;
        }
        _global.updateContext.reset();
    },
    onSurfaceChanged: function (width, height) {
        console.log('game.onSurfaceChanged', width, height);
        mCamera.lookAt([0, 0, 10], [0, 0, 0], [0, 1, 0]).ortho(0, width, 0, height, 9, 11);
        mRenderContext.onChange();
        mCamera.setViewport(width, height);
        mCamera.viewport();

        _global.onSizeChange(width, height);
    },
    onDrawFrame: function () {
//       console.log('game.onDrawFrame');
        _global.runSchedule();
        _framerate.update();
    }
};

module.exports = game;
