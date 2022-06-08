<script>
	const MopSdk = uni.requireNativePlugin('MopSdk');

	export default {
		onLaunch: function() {
			console.log('App Launch')
			MopSdk.initialize({
						'sdkKey': '22LyZEib0gLTQdU3MUauAa2CctUv+NxTLFWyPxC28y2gA4x+JWh7hhNS5aO52BFs',
						'sdkSecret': '65146ffa924ecfdc',
						'apmServer': 'https://api.finclip.com',
						//'apiServer': 'https://api.finclip.com',
						// 'apiPrefix': '/api/v1/mop/',
						// 'cryptType': 'MD5',
						// 'sdkFingerprint': '',
						// 'encryptServerData': false,
						// 'userId': '',
						// 'customWebViewUserAgent': '',
						// 'bindAppletWithMainProcess': false,
						// 'maxRunningApplet': 5,
						// 'apmExtension'
						// 'enableAppletDebug'
						// 'disablePermission': false,
						// 'disableGetSuperviseInfo'
						// 'disableRequestPermissions'
						// 小程序界面UI
						uiConfig: {
							//是否隐藏小程序加载界面的关闭按钮
							hideTransitionCloseButton: true,
							//屏蔽更多菜单中的“转发”按钮
							hideForwardMenu: false,
							//屏蔽更多菜单中的“设置”按钮
							hideSettingMenu: false,
							//屏蔽更多菜单中的“返回首页”按钮
							hideBackToHome: false,
							//屏蔽更多菜单中的“反馈与投诉”按钮
							hideFeedbackMenu: false,
							//SDK中“小程序”文案替换为任意其它名称
							//appletText: '小程序',
							//胶囊按钮配置
							capsuleConfig: {
								//右上角胶囊视图的宽度，默认值为88
								capsuleWidth: 88,
								//右上角胶囊视图的高度，默认值为32
								capsuleHeight: 32,
								//右上角胶囊视图的右边距
								capsuleRightMargin: 7,
								//右上角胶囊视图的圆角半径，默认值为5
								capsuleCornerRadius: 16,
								//右上角胶囊视图的边框宽度，默认值为0.8
								capsuleBorderWidth: 0.5,
								//胶囊背景颜色浅色
								capsuleBgLightColor: '0x00000000',
								//胶囊背景颜色深色
								capsuleBgDarkColor: '0x80ffffff',
								//右上角胶囊视图的边框浅色颜色
								capsuleBorderLightColor: '0x80ffffff',
								//右上角胶囊视图的边框深色颜色
								capsuleBorderDarkColor: '0x26000000',
								// 胶囊分割线浅色颜色
								capsuleDividerLightColor: '0x26ffffff',
								// 胶囊分割线深色颜色
								capsuleDividerDarkColor: '0x26000000',
								// 胶囊里的更多按钮的宽度，高度与宽度相等
								moreBtnWidth: 32,
								// 胶囊里的更多按钮的左边距
								moreBtnLeftMargin: 6,
								// 胶囊里的关闭按钮的宽度，高度与宽度相等
                                closeBtnWidth: 32,
								// 胶囊里的关闭按钮的左边距
								closeBtnLeftMargin: 6,
								//以下属性暂不支持，需原生工程调整
								//胶囊里的浅色更多按钮的图片对象，如果不传，会使用默认图标
								//moreLightImage
								//胶囊里的深色更多按钮的图片对象，如果不传，会使用默认图标
								//moreDarkImage
								//胶囊里的浅色更多按钮的图片对象，如果不传，会使用默认图标
							    //closeLightImage
								//胶囊里的深色更多按钮的图片对象，如果不传，会使用默认图标
								//closeDarkImage
							},
							//导航栏的返回首页按钮UI定制方法
							// navHomeConfig: {
							// 	//返回首页按钮宽度，默认44
							// 	width: 44,
							// 	//返回首页按钮高度，默认32
							// 	height: 32,
							// 	// 返回首页按钮的左边距，默认7
							// 	leftMargin: 7,
							// 	//返回首页按钮边框圆角半径，默认5
							// 	cornerRadius: 5,
							// 	//返回首页按钮边框宽度，默认1
							// 	borderWidth: 0.5,
							// 	//返回首页按钮浅色边框颜色，默认0X80FFFFFF
							// 	borderLightColor: '0x80ffffff',
							// 	//返回首页按钮深色边框颜色，默认0X26000000
							// 	borderDarkColor: '0x26000000',
							// 	//返回首页按钮浅色背景，默认0x33000000
							// 	bgLightColor: '0x33000000',
							// 	//返回首页按钮深色背景，默认0x33000000
							// 	bgDarkColor: '0x80ffffff',
							// 	//以下属性暂不支持，需要原生工程调整
							// 	//导航栏返回首页按钮浅色图标，如果不传，会使用默认图标
							// 	//lightImage
							// 	//导航栏返回首页按钮浅色图标，如果不传，会使用默认图标
							// 	//darkImage
							// },
							//浮窗设置窗口大小和位置，一般用于智能设备 如车载、手表、
							// floatWindowConfig: {
							// 	floatMode: true,
							// 	x: 0,
							// 	y: 0,
							// 	width: 0,
							// 	height: 0,
							// }
						}
					},
					(ret) => {
						console.log('App Launch Success', ret)
					},
					(ret) =>{
						console.log('App Launch Fail', ret)
					});
			//小程序生命周期
			MopSdk.setAppletLifecycleCallback(
				(ret) => {
					console.log('onInitComplete', ret)
				},
				(ret) => {
					console.log('onFailure', ret)
				},
				(ret) => {
					console.log('onCreate', ret)
				},
				(ret) => {
					console.log('onStart', ret)
				},
				(ret) => {
					console.log('onResume', ret)
				},
				(ret) => {
					console.log('onPause', ret)
				},
				(ret) => {
					console.log('onStop', ret)
				},
				(ret) => {
					console.log('onDestroy', ret)
				})		
			//注册小程序API
			MopSdk.registerExtensionApi('getMessage',  (ret) => {
				//该成功/失败事件必须有一个被调用，否则小程序无法接受到返回
				const { uuid } = ret //回调唯一标识
				
				//当前小程序appId
				console.log('小程序appId:',MopSdk.currentAppletId())
				//当前小程序信息
				console.log('小程序信息:',MopSdk.currentApplet())
				
				//成功返回
				MopSdk.onSuccess(uuid, {message: '成功了，我来自于Vue'})
				//错误返回
				//MopSdk.onFail(uuid, {message: 'Vue界面'})
			})
			//注册小程序web-view API
			// MopSdk.registerWebExtentionApi('getMessage', (ret) => {
			// 	const { uuid } = ret //回调唯一标识
			// 	//成功返回
			// 	MopSdk.onSuccess(uuid, {message: '成功了，我来自于Vue'})
			// 	//错误返回
			// 	//MopSdk.onFail(uuid, {message: 'Vue界面'})
			// })
			//原生发送事件给小程序
			// Mop.sendCustomEvent(appId, {
			// 	name: ''
			// })
			//原生发送事件给所有内存中的小程序
			// Mop.sendCustomEventToAll({
			// 	name: ''
			// })
			//原生调用webview中的js方法
			// MopSdk.callJS(appId,
			// eventName,
			// webViewId,
			// {
			//   name: ''
			// },(ret) => {
			// 	console.log('调用成功')
			// },(ret) => {
			// 	console.log('调用失败')
			// },(ret) => {
			// 	console.log('调用中')
			// })
			//搜索小程序
			// MopSdk.searchAppletss({
			// 	apiServer: '服务器域名',
			// 	text: '文本'
			// },(ret) => {
			// 	console.log('搜索成功',ret)
			// }, (ret) => {
			// 	console.log('搜索失败',ret)
			// }, (ret) => {
			// 	console.log('搜索中',ret)
			// })
			//关闭小程序 小程序会在内存中存在
			//MopSdk.closeApplet(appId)
			//关闭所有小程序
			//MopSdk.closeApplets()
			//结束小程序 ，从内存中移除
			//MopSdk.finishRunningApplet(appId)
			//结束所有小程序
			//MopSdk.finishRunningApplets()
			//清除小程序缓存
			//MopSdk.clearApplets()
			//小程序关闭事件
			MopSdk.setNavigationBarCloseButtonClicked((appId) => {
				console.log('setNavigationBarCloseButtonClicked',appId)
				//结束小程序
				MopSdk.finishRunningApplet(appId)
			})	
			//设置小程序button的open-type获取用户信息，一般APP登录帐号后进行设置
			// MopSdk.setUserInfo({
			// })
			//设置小程序button的open-type获取手机信息，一般APP登录帐号后进行设置
			// MopSdk.setGetPhoneNumber((ret) => {
			// 	const { uuid } = ret
			// 	MopSdk.onSuccess(uuid,{phoneNumber: '13800000000'})
			// })
			//设置自定义菜单
			// const items = [
			// 	{
			// 		id: '菜单ID',
			// 		title: '标题',
			// 		image: '图标地址',
			// 		//菜单条目类型[0]或[1]
			// 		type: 0,
			// 		//是否可点击
			// 		isEnable: true
			// 	}
			// ];
			// const handleClickItem = (ret) => {
			// 	const { uuid } = ret
			// 	MopSdk.onSuccess(uuid,ret)
			// }
			// MopSdk.setRegisteredMoreMenuItems(items,handleClickItem)
		},
		onShow: function() {
			//console.log('App Show')
		},
		onHide: function() {
			//console.log('App Hide')
		}
	}
</script>

<style>
	/*每个页面公共css */
</style>
