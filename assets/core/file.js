var clz = require('nativeclasses');

function jsImplement() {
    function File(url) {
    }
    File.prototype.loadAsset = function (path) {
    };
    File.prototype.getContent = function () {
        return '';
    };
    File.prototype.release = function () {
    };
}
var _file = clz.file || jsImplement();

function loadContent(path) {
	//console.log('loadContent-->01');
    var f = new _file();
	//console.log('loadContent-->02');
    f.loadAsset(path);
	//console.log('loadContent-->03');
    var s = f.getContent();
	//console.log('loadContent-->04', s);
    f.release();
	//console.log('loadContent-->05');

    return s;
}

module.exports = _file;
module.exports.loadContent = loadContent;