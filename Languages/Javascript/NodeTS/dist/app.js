"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var express = require("express");
var bodyParser = require("body-parser");
var App = /** @class */ (function () {
    function App() {
        this.app = express();
        this.config();
        this.routes();
    }
    App.prototype.config = function () {
        this.app
            .use(bodyParser.json())
            .use(bodyParser.urlencoded({
            extended: false
        }));
    };
    App.prototype.routes = function () {
        var router = express.Router();
        router.get('*', function (request, response) {
            var url = request.url;
            var method = request.method;
            var details = method + " " + url;
            console.log(details);
            response
                .status(200)
                .send(details);
        });
        this.app.use('/', router);
    };
    return App;
}());
exports.default = App;
