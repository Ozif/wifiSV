Page({

  /**
   * 页面的初始数据
   */
  data: {
    ip: "192.168.1.176",
  },

  /**
   * 提交连接请求
   * 1. 获取输入的IP地址
   * 2. 发送请求到机械臂
   * 3. 成功则跳转到控制页
   * 4. 失败显示错误信息
   */
  submit() {
    let ip = this.data.ip;
    console.log(`http://${ip}`);
    wx.request({
      url: `http://${ip}`,
      success: (res) => {
        if (res.data == "open") {
          wx.showToast({
            title: '连接成功',
            icon: "loading"
          })
          setTimeout(() => {
            wx.reLaunch({
              url: `/pages/control/control?url=http://${ip}`,
            })
          }, 2000)
        }
      },
      fail: (err) => {
        wx.showToast({
          title: err.errMsg,
          icon: "none",
          mask: true
        })
      }
    });
  },

  /**
   * 生命周期函数--监听页面加载
   */
  onLoad: function (options) { },

  /**
   * 生命周期函数--监听页面初次渲染完成
   */
  onReady: function () {

  },

  /**
   * 生命周期函数--监听页面显示
   */
  onShow: function () {

  },

  /**
   * 生命周期函数--监听页面隐藏
   */
  onHide: function () {

  },

  /**
   * 生命周期函数--监听页面卸载
   */
  onUnload: function () {

  },

  /**
   * 页面相关事件处理函数--监听用户下拉动作
   */
  onPullDownRefresh: function () {

  },

  /**
   * 页面上拉触底事件的处理函数
   */
  onReachBottom: function () {

  },

  /**
   * 用户点击右上角分享
   */
  onShareAppMessage: function () {

  }
})