<template>
	<view class="content">
		<image class="logo" src="/static/logo.png"></image>
		<button type="primary" v-on:click="handleOpenMiniProgram">打开小程序</button>
		<view class="padding-gap"></view>
		<button type="primary" v-on:click="handleOpenMiniProgramByQrcode">二维码打开小程序</button>
	    <view class="padding-gap"></view>
		<button type="primary" v-on:click="handleFinishMiniProgram">结束小程序</button>
		<view class="padding-gap"></view>
		<button type="primary" v-on:click="handleFinishAllMiniProgram">结束所有小程序</button>
		<view class="padding-gap"></view>
		<button type="primary" v-on:click="handleSendMessageToMiniProgram">发送信息小程序</button>
		<view class="padding-gap"></view>
		<button type="primary" v-on:click="handleGetMiniProgramInfo">获前小程序信息</button>
		<view class="padding-gap"></view>
		<button type="primary" v-on:click="handleSearchMiniProgram">搜索小程序</button>
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
		onLoad() {
		},
		methods: {
			handleOpenMiniProgram() {
				const apiServer = 'https://api.finclip.com'
				const appId = '62566cbd3eb8ce0001b7761c'
				const startParams = {
					path: '/pages/index/index',
					query: 'a=1&b=2'
				}
				const sequence = null // 小程序的上架序列号
				const isSingleton = false //安卓单任栈（）
				MopSdk.openApplet({apiServer,
				                   appId,
								   startParams,
								   sequence,
								   isSingleton})
			},
			handleOpenMiniProgramByQrcode() {
				uni.scanCode({
					success: (result) => {
						console.log(result)
						const qrCode = result.result
						const isSingleton = false
						MopSdk.openAppletByQrcode({qrCode,isSingleton},
						                  (ret) => {
											  console.log('onSuccess',ret)	
										  },
										  (ret) => {
											  console.log('onFail',ret)	
										  },
										  (ret) => {
										  	console.log('onProcess',ret)								  
										  })
					}
				})	
			},
			handleFinishMiniProgram(){
				MopSdk.finishRunningApplet('62566cbd3eb8ce0001b7761c')
			},
			handleFinishAllMiniProgram(){
				MopSdk.finishAllRunningApplets()
			},
			handleSendMessageToMiniProgram(){
				MopSdk.currentAppletId((res) => {
					console.log('当前小程序appId:',res.currentAppletId)
					// MopSdk.sendCustomEvent(res.currentAppletId,{
					// 	message: 'this is test'
					// })
					MopSdk.sendCustomEventToAll({
						message: 'this is test'
					})
				})
			},
			handleGetMiniProgramInfo() {
				MopSdk.currentApplet((res) => {
					console.log('当前小程序信息',res)
				})
			},
			handleSearchMiniProgram() {
				MopSdk.seachApplets({
					apiServer: 'https://api.finclip.com',
					text: '测试'
				},(res) => {
					console.log('搜索小程序结果',res)
				})
			}
		}
	}
</script>

<style>
	.content {
		display: flex;
		flex-direction: column;
		align-items: center;
		justify-content: center;
	}

	.logo {
		height: 200rpx;
		width: 200rpx;
		margin-top: 200rpx;
		margin-left: auto;
		margin-right: auto;
		margin-bottom: 50rpx;
	}

	.text-area {
		display: flex;
		justify-content: center;
	}
	.padding-gap {
		height: 30rpx;
	}

	.title {
		font-size: 36rpx;
		color: #8f8f94;
	}
</style>
