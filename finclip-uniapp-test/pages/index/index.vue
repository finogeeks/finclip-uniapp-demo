<template>
	<view class="box">
		<view class="box-item" v-on:click="handleSDKInit">初始化SDK</view>
		
		<view class="box-item" v-on:click="handleMiniProgramLifecycle">小程序生命周期</view>
		<view class="box-item" v-on:click="handleOpenMiniProgram">打开小程序</view>
		<view class="box-item" v-on:click="handleOpenMiniProgramByQrcode">二维码打开小程序</view>
		<view class="box-item" v-on:click="handleSearchMiniProgram">搜索小程序</view>
		<view class="box-item" v-on:click="handleDownloadMiniProgram">批量下载小程序</view>
		<view class="box-item" v-on:click="handleCaptureMiniProgramPicture">小程序截图</view>
		<view class="box-item" v-on:click="handleMoveMiniProgramToFront">小程序移至前端</view>
		<view class="box-item" v-on:click="handleMoveAppToFront">APP移至前端</view>
		<view class="box-item" v-on:click="handleGetMiniProgramAppID">获取小程序appId</view>
		<view class="box-item" v-on:click="handleGetMiniProgramInfo">获取小程序信息</view>
		<view class="box-item" v-on:click="handleGetUsedMiniProgram">获取使用小程序信息</view>
		<view class="box-item" v-on:click="handleGetUsedMiniProgramList">获取使用小程序列表</view>
		<view class="box-item" v-on:click="handleIsUsedMiniProgram">小程序是否使用</view>
		<view class="box-item" v-on:click="handleCloseMiniProgram">关闭小程序</view>
		<view class="box-item" v-on:click="handleCloseAllMiniProgram">关闭所有小程序</view>
		<view class="box-item" v-on:click="handleFinishMiniProgram">结束小程序</view>
		<view class="box-item" v-on:click="handleFinishAllMiniProgram">结束所有小程序</view>
		<view class="box-item" v-on:click="handleClearMiniProgram">清除小程序</view>
		<view class="box-item" v-on:click="handleClearAllMiniProgram">清除所有小程序</view>
		
		<view class="box-item" v-on:click="handleRegisterExtensionApi">注册自定义Api</view>
		<view class="box-item" v-on:click="handleUnRegisterExtensionApi">取消注册自定义Api</view>
		<view class="box-item" v-on:click="handleRegisterWebExtensionApi">注册WebView自定义Api</view>
		<view class="box-item" v-on:click="handleUnRegisterWebExtensionApi">取消WebView注册自定义Api</view>
		
		<view class="box-item" v-on:click="handleSetChooseAvatar">设置获取头像</view>
		<view class="box-item" v-on:click="handleSetPhoneNumber">设置获取手机号</view>
		<view class="box-item" v-on:click="handleSetOpenTypeShareAppMessage">设置按钮分享代理</view>
		<view class="box-item" v-on:click="handleSetShareAppMessage">设置菜单分享代理</view>
		<view class="box-item" v-on:click="handleSetUserInfo">设置用户信息</view>
		<view class="box-item" v-on:click="handleSetRegisteredMoreMenuItems">设置菜单界面按钮</view>
		<view class="box-item" v-on:click="handleSetGrayAppletVersionConfigs">设置灰度键值</view>
		
		
		<view class="box-item" v-on:click="handleGetCurrentWebViewURL">webView的URL</view>
		<view class="box-item" v-on:click="handleGetCurrentWebViewUserAgent">webView的userAgent</view>
		<view class="box-item" v-on:click="handleSetWebViewCookie">设置webView的cookies</view>
		<view class="box-item" v-on:click="handleRemoveWebViewCookie">删除webView的cookies</view>
		<view class="box-item" v-on:click="handleRemoveWebViewAllCookie">删除所有cookies</view>
		
		<view class="box-item" v-on:click="handleSendMessageToMiniProgram">发送信息小程序</view>
		<view class="box-item" v-on:click="handleSendMessageToAllMiniProgram">发送信息所有小程序</view>
	
	    <view class="box-item" v-on:click="handleSetUserId">设置数据隔离/体验</view>
	    <view class="box-item" v-on:click="handleGetFinFileAbsolutePath">转换绝对路径</view>
		
		<view class="box-item" v-on:click="handleRegisterExtSDK">注册扩展SDK</view>
		<view class="box-item" v-on:click="handleRegisterBDMapSDK">注册百度地图</view>
		<view class="box-item" v-on:click="handleRegisterGDMapSDK">注册高德地图</view>
		<view class="box-item" v-on:click="handleRegisterTXMapSDK">注册腾讯地图</view>
		<view class="box-item" v-on:click="handleRegisterBluetoothSDK">注册蓝牙SDK</view>
		<view class="box-item" v-on:click="handleRegisterContactSDK">注册联系人SDK</view>
		<view class="box-item" v-on:click="handleRegisterClipboardSDK">注册剪贴板SDK</view>
		<view class="box-item" v-on:click="handleRegisterLiveSDK">注册直插SDK</view>
		<view class="box-item" v-on:click="handleRegisterCalendarSDK">注册日历SDK</view>
	</view>
</template>

<script>
	const MopSdk = uni.requireNativePlugin('MopSdk');
	export default {
		data() {
			return {
				title: 'Hello'
			}
		},
		onLoad() {},
		methods: {
			handleSDKInit() {
				MopSdk.initialize({
						finStoreConfigs: [{
							'sdkKey': 'DJdcqU1zIndfppo+jhIryatbJ0PaKhO1lSssgibwZ5U=',
							'sdkSecret': '7dccd26f1774f6a0',
							'apiServer': 'https://api.finclip.com',
						}],
						appletDebugMode: true,
						uiConfig: {
							isHideFeedbackAndComplaints: false,
							isHideShareAppletMenu: false,
							capsuleConfig: {
								capsuleCornerRadius: 16
							}
						}
					}, (ret) => {
						console.log('App Launch Success', ret)
					},
					(ret) => {
						console.log('App Launch Fail', ret)
					})
			},
			handleMiniProgramLifecycle() {
				MopSdk.setAppletLifecycleCallback(
					(ret) => {
						console.log('onInitComplete', ret)
					},
					(ret) => {
						console.log('onOpen', ret)
					},
					(ret) => {
						console.log('onOpenFailure', ret)
					},
					(ret) => {
						console.log('onInActive', ret)
					},
					(ret) => {
						console.log('onActive', ret)
					},
					(ret) => {
						console.log('onClose', ret)
					},
					(ret) => {
						console.log('onDestroy', ret)
					})
			},
			handleOpenMiniProgram() {
				const apiServer = 'https://api.finclip.com'
				const appId = '62ac4ba2819a3b00014cefcd'
				MopSdk.openApplet({
					apiServer,
					appId
				})
			},
			handleOpenMiniProgramByQrcode() {
				uni.scanCode({
					success: (result) => {
						const qrCode = result.result
						MopSdk.openAppletByQrcode({
								qrCode
							},
							(ret) => {
								console.log('onSuccess', ret)
							},
							(ret) => {
								console.log('onFail', ret)
							},
							(ret) => {
								console.log('onProcess', ret)
							})
					}
				})
			},
			handleSearchMiniProgram() {
				MopSdk.searchApplets({
					apiServer: 'https://api.finclip.com',
					text: '测试'
				}, (res) => {
					console.log('搜索小程序成功', res)
				}, (res) => {
					console.log('搜索小程序失败', res)
				}, (res) => {
					console.log('搜索小程序进行中', res)
				})
			},
			handleDownloadMiniProgram() {
				MopSdk.downloadApplets({
					apiServer: 'https://api.finclip.com',
					appIds: ['62ac4ba2819a3b00014cefcd'],
					isBatchDownloadApplets: true
				}, (res) => {
					console.log('下载小程序结果', res)
				}, (res) => {
					console.log('下载小程序失败', res)
				})
			},
			handleCaptureMiniProgramPicture() {
				setTimeout(()=> {
					MopSdk.captureAppletPicture('62ac4ba2819a3b00014cefcd',
						false,
						(res) => {
							console.log('小程序截图结果', res)
						}, (res) => {
							console.log('小程序截图失败', res)
					})
				}, 3000)
				
			},
			handleMoveMiniProgramToFront() {
				MopSdk.moveMiniProgramToFront('62ac4ba2819a3b00014cefcd')
			},
			handleMoveAppToFront() {
				setTimeout(()=> {
					MopSdk.moveAppToFront()
				},3000)
			},
			handleGetMiniProgramAppID() {
				setTimeout(()=> {
					MopSdk.currentAppletId((res) => {
						console.log('当前小程序AppId', res)
					})
				} ,3000)
			},
			handleGetMiniProgramInfo() {
				setTimeout(()=> {
					MopSdk.currentApplet((res) => {
						console.log('当前小程序信息', res)
					})
				},3000)
			},
			handleGetUsedMiniProgram() {
				MopSdk.getUsedApplet('62ac4ba2819a3b00014cefcd', (res) => {
					console.log('获取使用小程序信息', res)
				})
			},
			handleGetUsedMiniProgramList() {
				MopSdk.getUsedApplets((res) => {
					console.log('获取使用小程序列表', res)
				})
			},
			handleIsUsedMiniProgram() {
				MopSdk.isUsedApplet('62ac4ba2819a3b00014cefcd', (res) => {
					console.log('小程序是否使用', res)
				})
			},
			handleCloseMiniProgram() {
				MopSdk.closeApplet('62ac4ba2819a3b00014cefcd')
			},
			handleFinishAllMiniProgram() {
				MopSdk.closeApplets()
			},
			handleFinishMiniProgram() {
				MopSdk.finishRunningApplet('62ac4ba2819a3b00014cefcd')
			},
			handleFinishAllMiniProgram() {
				MopSdk.finishRunningApplets()
			},
			handleClearMiniProgram() {
				MopSdk.clearApplet('62ac4ba2819a3b00014cefcd')
			},
			handleClearAllMiniProgram() {
				MopSdk.clearApplets()
			},
			handleRegisterExtensionApi() {
				MopSdk.registerExtensionApi('miniLogin', (ret) => {
					uni.showModal({
						content: JSON.stringify(ret)
					})

					MopSdk.onSuccess(ret.uuid, {
						token: 'xxxxxx'
					})
				})
			},
			handleUnRegisterExtensionApi() {
				MopSdk.unRegisterExtensionApi('miniLogin')
			},
			handleRegisterWebExtensionApi() {
				MopSdk.registerWebExtensionApi('miniLogin', (ret) => {
					uni.showModal({
						content: JSON.stringify(ret)
					})

					MopSdk.onSuccess(ret.uuid, {
						token: 'xxxxxx'
					})
				})
			},
			handleUnRegisterWebExtensionApi() {
				MopSdk.unRegisterWebExtensionApi('miniLogin')
			},
			handleSetChooseAvatar(){
				MopSdk.setChooseAvatar('https://finclip.com/img/finclip_nav_logo_color.5492fca2.png')
			},
			handleSetPhoneNumber(){
				MopSdk.setPhoneNumber('13549900000')
			},
			handleSetOpenTypeShareAppMessage(){
				MopSdk.setOpenTypeShareAppMessage((res) => {
					console.log('分享按钮代理',res)
				})
			},
			handleSetShareAppMessage(){
				MopSdk.setShareAppMessage((res) => {
					console.log('菜单分享代理',res)
				})
			},
			handleSetUserInfo(){
				MopSdk.setUserInfo({
					name: 'xxx',
					sex: '女'
				})
			},
			handleSetRegisteredMoreMenuItems(){
				MopSdk.setRegisteredMoreMenuItems([{
					id: 'test01',
					title: '测试'
				}],(res) => {
					console.log('自定义菜单按钮事件',res)
				})
			},
			handleSetGrayAppletVersionConfigs(){
				MopSdk.setGrayAppletVersionConfigs([{
					key: 'userId',
					value: '13500000000'
				}])
			},
			handleGetCurrentWebViewURL(){
				MopSdk.getCurrentWebViewURL((res) =>{
					console.log('获取当前小程序webView的URL成功',res)
				},(res) =>{
					console.log('获取当前小程序webView的URL失败',res)
				},(res) =>{
					console.log('获取当前小程序webView的进行中',res)
				})
			},
			handleGetCurrentWebViewUserAgent(){
				MopSdk.getCurrentWebViewUserAgent((res) =>{
					console.log('获取当前小程序webView的UserAgent成功',res)
				},(res) =>{
					console.log('获取当前小程序webView的UserAgent失败',res)
				},(res) =>{
					console.log('获取当前小程序webView的进行中',res)
				})
			},
			handleSetWebViewCookie(){
				MopSdk.setWebViewCookie({
					appId: '62ac4ba2819a3b00014cefcd',
					url: 'https://',
					cookies: 'key=value;key2=value2'
				})
			},
			handleRemoveWebViewCookie(){
				MopSdk.removeWebViewCookie({
					appId: '62ac4ba2819a3b00014cefcd',
					url: 'https://'
				})
			},
			handleRemoveWebViewAllCookie(){
				MopSdk.removeWebViewAllCookie({
					appId: '62ac4ba2819a3b00014cefcd'
				})
			},
			handleSendMessageToMiniProgram() {
				MopSdk.sendCustomEvent('62ac4ba2819a3b00014cefcd', {
					message: 'this is test'
				})
			},
			handleSendMessageToAllMiniProgram() {
				MopSdk.sendCustomEventToAll({
					message: 'this is all test'
				})
			},
			handleSetUserId(){
				MopSdk.setUserId('13500000000')
			},
			handleGetFinFileAbsolutePath(){
				MopSdk.getFinFileAbsolutePath('62ac4ba2819a3b00014cefcd','finfile://',(res) =>{
					console.log('获取绝对路径',res)
				})
			},
			handleRegisterExtSDK() {
				MopSdk.registerExtSDK()
			},
			handleRegisterBDMapSDK() {
				MopSdk.registerBDMapSDK('xxxxxx')
			},
			handleRegisterGDMapSDK() {
				MopSdk.registerGDMapSDK('xxxxxx')
			},
			handleRegisterTXMapSDK() {
				MopSdk.registerTXMapSDK('xxxxxx')
			},
			handleRegisterBluetoothSDK() {
				MopSdk.registerBluetoothSDK()
			},
			handleRegisterContactSDK() {
				MopSdk.registerContactSDK()
			},
			handleRegisterClipboardSDK() {
				MopSdk.registerClipboardSDK()
			},
			handleRegisterLiveSDK() {
				MopSdk.registerLiveSDK()
			},
			handleRegisterCalendarSDK() {
				MopSdk.registerCalendarSDK()
			}
		}
	}
</script>

<style>
	.box {
		display: flex;
		flex-wrap: wrap;
	}

	.box-item {
		width: 30%;
		height: 80px;
		line-height: 80px;
		background-color: aqua;
		border-radius: 10px;
		margin: 5px;
		text-align: center;
		justify-content: center;
		font-size: 12px;
	}
</style>