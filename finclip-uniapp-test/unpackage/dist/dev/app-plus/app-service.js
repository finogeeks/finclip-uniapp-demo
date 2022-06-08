if (typeof Promise !== "undefined" && !Promise.prototype.finally) {
  Promise.prototype.finally = function(callback) {
    const promise = this.constructor;
    return this.then((value) => promise.resolve(callback()).then(() => value), (reason) => promise.resolve(callback()).then(() => {
      throw reason;
    }));
  };
}
;
if (typeof uni !== "undefined" && uni && uni.requireGlobal) {
  const global = uni.requireGlobal();
  ArrayBuffer = global.ArrayBuffer;
  Int8Array = global.Int8Array;
  Uint8Array = global.Uint8Array;
  Uint8ClampedArray = global.Uint8ClampedArray;
  Int16Array = global.Int16Array;
  Uint16Array = global.Uint16Array;
  Int32Array = global.Int32Array;
  Uint32Array = global.Uint32Array;
  Float32Array = global.Float32Array;
  Float64Array = global.Float64Array;
  BigInt64Array = global.BigInt64Array;
  BigUint64Array = global.BigUint64Array;
}
;
if (uni.restoreGlobal) {
  uni.restoreGlobal(Vue, weex, plus, setTimeout, clearTimeout, setInterval, clearInterval);
}
(function(vue, shared) {
  "use strict";
  function isDebugMode() {
    return typeof __channelId__ === "string" && __channelId__;
  }
  function jsonStringifyReplacer(k, p) {
    switch (shared.toRawType(p)) {
      case "Function":
        return "function() { [native code] }";
      default:
        return p;
    }
  }
  function normalizeLog(type, filename, args) {
    if (isDebugMode()) {
      args.push(filename.replace("at ", "uni-app:///"));
      return console[type].apply(console, args);
    }
    const msgs = args.map(function(v) {
      const type2 = shared.toTypeString(v).toLowerCase();
      if (["[object object]", "[object array]", "[object module]"].indexOf(type2) !== -1) {
        try {
          v = "---BEGIN:JSON---" + JSON.stringify(v, jsonStringifyReplacer) + "---END:JSON---";
        } catch (e) {
          v = type2;
        }
      } else {
        if (v === null) {
          v = "---NULL---";
        } else if (v === void 0) {
          v = "---UNDEFINED---";
        } else {
          const vType = shared.toRawType(v).toUpperCase();
          if (vType === "NUMBER" || vType === "BOOLEAN") {
            v = "---BEGIN:" + vType + "---" + v + "---END:" + vType + "---";
          } else {
            v = String(v);
          }
        }
      }
      return v;
    });
    return msgs.join("---COMMA---") + " " + filename;
  }
  function formatAppLog(type, filename, ...args) {
    const res = normalizeLog(type, filename, args);
    res && console[type](res);
  }
  function requireNativePlugin(name) {
    return weex.requireModule(name);
  }
  var _export_sfc = (sfc, props) => {
    const target = sfc.__vccOpts || sfc;
    for (const [key, val] of props) {
      target[key] = val;
    }
    return target;
  };
  const MopSdk$1 = requireNativePlugin("MopSdk");
  const _sfc_main$1 = {
    data() {
      return {
        title: "Hello"
      };
    },
    onLoad() {
    },
    methods: {
      handleOpenMiniProgram() {
        const apiServer = "https://api.finclip.com";
        const appId = "5eec56a41464cc0001852e9a";
        const startParams = null;
        const sequence = null;
        MopSdk$1.openApplet(apiServer, appId, startParams, sequence);
      },
      handleOpenMiniProgramByQrcode() {
        uni.scanCode({
          success: (result) => {
            formatAppLog("log", "at pages/index/index.vue:39", result);
            const qrcode = result.result;
            MopSdk$1.openAppletByQrcode(qrcode, (ret) => {
              formatAppLog("log", "at pages/index/index.vue:43", "onSuccess", ret);
            }, (ret) => {
              formatAppLog("log", "at pages/index/index.vue:46", "onFail", ret);
            }, (ret) => {
              formatAppLog("log", "at pages/index/index.vue:49", "onProcess", ret);
            });
          }
        });
      }
    }
  };
  function _sfc_render(_ctx, _cache, $props, $setup, $data, $options) {
    return vue.openBlock(), vue.createElementBlock("view", { class: "content" }, [
      vue.createElementVNode("image", {
        class: "logo",
        src: "/static/logo.png"
      }),
      vue.createElementVNode("button", {
        type: "primary",
        onClick: _cache[0] || (_cache[0] = (...args) => $options.handleOpenMiniProgram && $options.handleOpenMiniProgram(...args))
      }, "\u6253\u5F00\u5C0F\u7A0B\u5E8F"),
      vue.createElementVNode("view", { class: "padding-gap" }),
      vue.createElementVNode("button", {
        type: "primary",
        onClick: _cache[1] || (_cache[1] = (...args) => $options.handleOpenMiniProgramByQrcode && $options.handleOpenMiniProgramByQrcode(...args))
      }, "\u4E8C\u7EF4\u7801\u6253\u5F00\u5C0F\u7A0B\u5E8F")
    ]);
  }
  var PagesIndexIndex = /* @__PURE__ */ _export_sfc(_sfc_main$1, [["render", _sfc_render], ["__file", "/Users/yangbin/work/finogeeks/newspace/finclip-uniapp-demo/finclip-uniapp-test/pages/index/index.vue"]]);
  __definePage("pages/index/index", PagesIndexIndex);
  const MopSdk = requireNativePlugin("MopSdk");
  const _sfc_main = {
    onLaunch: function() {
      formatAppLog("log", "at App.vue:6", "App Launch");
      MopSdk.initialize({
        "sdkKey": "22LyZEib0gLTQdU3MUauAa2CctUv+NxTLFWyPxC28y2gA4x+JWh7hhNS5aO52BFs",
        "sdkSecret": "65146ffa924ecfdc",
        "apmServer": "https://api.finclip.com",
        uiConfig: {
          hideTransitionCloseButton: true,
          hideForwardMenu: false,
          hideSettingMenu: false,
          hideBackToHome: false,
          hideFeedbackMenu: false,
          capsuleConfig: {
            capsuleWidth: 88,
            capsuleHeight: 32,
            capsuleRightMargin: 7,
            capsuleCornerRadius: 16,
            capsuleBorderWidth: 0.5,
            capsuleBgLightColor: "0x00000000",
            capsuleBgDarkColor: "0x80ffffff",
            capsuleBorderLightColor: "0x80ffffff",
            capsuleBorderDarkColor: "0x26000000",
            capsuleDividerLightColor: "0x26ffffff",
            capsuleDividerDarkColor: "0x26000000",
            moreBtnWidth: 32,
            moreBtnLeftMargin: 6,
            closeBtnWidth: 32,
            closeBtnLeftMargin: 6
          }
        }
      }, (ret) => {
        formatAppLog("log", "at App.vue:118", "App Launch Success", ret);
      }, (ret) => {
        formatAppLog("log", "at App.vue:121", "App Launch Fail", ret);
      });
      MopSdk.setAppletLifecycleCallback((ret) => {
        formatAppLog("log", "at App.vue:126", "onInitComplete", ret);
      }, (ret) => {
        formatAppLog("log", "at App.vue:129", "onFailure", ret);
      }, (ret) => {
        formatAppLog("log", "at App.vue:132", "onCreate", ret);
      }, (ret) => {
        formatAppLog("log", "at App.vue:135", "onStart", ret);
      }, (ret) => {
        formatAppLog("log", "at App.vue:138", "onResume", ret);
      }, (ret) => {
        formatAppLog("log", "at App.vue:141", "onPause", ret);
      }, (ret) => {
        formatAppLog("log", "at App.vue:144", "onStop", ret);
      }, (ret) => {
        formatAppLog("log", "at App.vue:147", "onDestroy", ret);
      });
      MopSdk.registerExtensionApi("getMessage", (ret) => {
        const { uuid } = ret;
        formatAppLog("log", "at App.vue:155", "\u5C0F\u7A0B\u5E8FappId:", MopSdk.currentAppletId());
        formatAppLog("log", "at App.vue:157", "\u5C0F\u7A0B\u5E8F\u4FE1\u606F:", MopSdk.currentApplet());
        MopSdk.onSuccess(uuid, { message: "\u6210\u529F\u4E86\uFF0C\u6211\u6765\u81EA\u4E8EVue" });
      });
      MopSdk.setNavigationBarCloseButtonClicked((appId) => {
        formatAppLog("log", "at App.vue:216", "setNavigationBarCloseButtonClicked", appId);
        MopSdk.finishRunningApplet(appId);
      });
    },
    onShow: function() {
    },
    onHide: function() {
    }
  };
  var App = /* @__PURE__ */ _export_sfc(_sfc_main, [["__file", "/Users/yangbin/work/finogeeks/newspace/finclip-uniapp-demo/finclip-uniapp-test/App.vue"]]);
  function createApp() {
    const app = vue.createVueApp(App);
    return {
      app
    };
  }
  const { app: __app__, Vuex: __Vuex__, Pinia: __Pinia__ } = createApp();
  uni.Vuex = __Vuex__;
  uni.Pinia = __Pinia__;
  __app__.provide("__globalStyles", __uniConfig.styles);
  __app__._component.mpType = "app";
  __app__._component.render = () => {
  };
  __app__.mount("#app");
})(Vue, uni.VueShared);
