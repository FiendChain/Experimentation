"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
var app_1 = require("./app");
var app = new app_1.default().app;
var port = 4001;
var hostname = "127.0.0.100";
app.listen(port, hostname, function () {
    console.log("Express server listening on " + hostname + ":" + port);
});
