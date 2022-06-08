<template>
	<view class="content">
		<image class="logo" src="/static/logo.png"></image>
		<button type="primary" v-on:click="handleOpenMiniProgram">打开小程序</button>
		<view class="padding-gap"></view>
		<button type="primary" v-on:click="handleOpenMiniProgramByQrcode">二维码打开小程序</button>
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
				const appId = '5eec56a41464cc0001852e9a'
				const startParams = null
				// const startParams = {
				// 	path: '/pages/index/index',
				// 	query: 'a=1&b=2'
				// }
				const sequence = null // 小程序的上架序列号
				MopSdk.openApplet(apiServer,
				                  appId,
								  startParams,
								  sequence)
			},
			handleOpenMiniProgramByQrcode() {
				uni.scanCode({
					success: (result) => {
						console.log(result)
						const qrcode = result.result
						MopSdk.openAppletByQrcode(qrcode,
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
