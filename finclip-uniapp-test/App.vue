<script>
	const MopSdk = uni.requireNativePlugin('MopSdk');

	export default {
		onLaunch: function(options) {
			
		},
		onShow: function() {
			//console.log('App Show')
		},
		onHide: function() {
			//console.log('App Hide')
		},
		onShareAppMessage: function() {
		// 返回分享的内容
		    return {
		      title: '分享的标题',
		      path: '/pages/index/index',
		      imageUrl: ''
		    }
		}
	}
</script>

<style>
	/*每个页面公共css */
</style>