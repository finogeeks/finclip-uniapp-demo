<script>
	const MopSdk = uni.requireNativePlugin('MopSdk');

	export default {
		onLaunch: function() {
			console.log('App Launch')
			MopSdk.initialize({
						'sdkKey': '22LyZEib0gLTQdU3MUauAa2CctUv+NxTLFWyPxC28y2gA4x+JWh7hhNS5aO52BFs',
						'sdkSecret': '65146ffa924ecfdc',
						'apmServer': 'https://api.finclip.com',
						'apiServer': 'https://api.finclip.com',
						'enableAppletDebug': true,
						'uiConfig': {
							'hideTechSupport': true
						}
					},
					(ret) => {
						console.log('App Launch Success', ret)
					},
					(ret) =>{
						console.log('App Launch Fail', ret)
					})
			//小程序关闭按钮事件
			MopSdk.setNavigationBarCloseButtonClicked((res) => {
				console.log('小程序关闭按钮事件', res)
			})
			//设置小程序button获取用户信息getUserInfo
			MopSdk.setUserInfo({
				name: '测试',
				sex: '男'
			},(res) => {
				console.log('设置小程序用户信息成功', JSON.stringify(res))
			},(res) => {
				console.log('设置小程序用户信息失败', JSON.stringify(res))
			})
			//设置小程序button获取用户头像信息chooseavatar
			MopSdk.setChooseAvatar('https://dddd.com/12121.jpg')
			//设置小程序button获取用户手机信息getPhoneNumber
			MopSdk.setGetPhoneNumber('13800000000')
			
			//自定义小程序API
			MopSdk.registerExtensionApi('getJWToken', (res) => {
				
				//回调值
				MopSdk.onSuccess(res.uuid, {
				    jwToken : 'jwToken'
				})
			})
			MopSdk.registerExtensionApi('getJWToken2', (res) => {
				//回调值
				MopSdk.onSuccess(res.uuid, {
				    jwToken2 : 'jwToken2'
				})
			})
			//自定义小程序webview API
			MopSdk.registerWebExtentionApi('getJWToken', (res) => {
				
				//回调值
				MopSdk.onSuccess(res.uuid, {
				    jwToken : 'webview===>jwToken'
				})
			})
			MopSdk.registerWebExtentionApi('getJWToken2', (res) => {
				//回调值
				MopSdk.onSuccess(res.uuid, {
				    jwToken2 : 'webview===>jwToken2'
				})
			})
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
