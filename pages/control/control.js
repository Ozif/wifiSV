/**
 * 控制页面逻辑
 * 功能：
 * 1. 显示颜色选择网格
 * 2. 处理颜色选择事件
 * 3. 与机械臂通信（方向控制用对象数组表示）
 */
Page({
  data: {
    url: "",
    colorItem: [{
      color: "red",
      LAB: "L53,A80,B67"
    },
    {
      color: "blue",
      LAB: "L32,A79,B-108"
    },
    {
      color: "black",
      LAB: "L0,A0,B0"
    },
    {
      color: "yellow",
      LAB: "L97,A-21,B94"
    },
    ],
    // 九宫格方向控制对象数组（icon: 图标符号，id: 方位标识）
    dirItem: [{
      icon: "↖",
      id: "左上"
    }, // 第一行：左上
    {
      icon: "↑",
      id: "上"
    }, // 第一行：上
    {
      icon: "↗",
      id: "右上"
    }, // 第一行：右上
    {
      icon: "←",
      id: "左"
    }, // 第二行：左
    {
      icon: "·",
      id: "中间"
    }, // 第二行：中间（占位）
    {
      icon: "→",
      id: "右"
    }, // 第二行：右
    {
      icon: "↙",
      id: "左下"
    }, // 第三行：左下
    {
      icon: "↓",
      id: "下"
    }, // 第三行：下
    {
      icon: "↘",
      id: "右下"
    }, // 第三行：右下
    ],
    get: {
      color: "L0,A0,B0",
      dir: "中间"
    }
  },

  getColor(e) {
    this.setData({
      get: {
        color: e.target.id,
        dir: this.data.get.dir
      },
    })
    wx.showToast({
      icon: "none",
      title: this.data.get.color + this.data.get.dir
    })
  },
  getDir(e) {
    this.setData({
      get: {
        color: this.data.get.color,
        dir: e.target.id
      },
    }),
      wx.showToast({
        icon: "none",
        title: this.data.get.color + this.data.get.dir
      })
  },
  /**
   * 提交数据到服务器
   * 1. 显示加载状态
   * 2. 发送颜色和方向数据
   * 3. 处理成功/失败回调
   */
  Sub() {
    wx.showLoading({
      title: '发送中...',
      mask: true
    })
    
    wx.request({
      url: `${this.data.url}/putdata`,
      method: 'POST', // 明确指定POST方法
      data: JSON.stringify({ // 序列化数据
        color: this.data.get.color,
        dir: this.data.get.dir
      }),
      header: {
        'content-type': 'application/json' // 设置JSON请求头
      },
      success: (res) => {
        wx.hideLoading()
        if (res.statusCode === 200) {
          wx.showToast({
            title: '指令发送成功',
            icon: 'success'
          })
        } else {
          wx.showToast({
            title: `错误: ${res.data || '未知错误'}`,
            icon: 'none'
          })
        }
      },
      fail: (err) => {
        wx.hideLoading()
        wx.showToast({
          title: `网络错误: ${err.errMsg}`,
          icon: 'none'
        })
      }
    })
  },
  /**
   * 生命周期函数--监听页面加载
   */
  onLoad(options) {
    //获取页面参数
    if (options.url) {
      this.setData({
        url: options.url
      })
    }
    //请求颜色数据
    // this.getData()
  },

  /**
   * 生命周期函数--监听页面初次渲染完成
   */
  onReady() {

  },

  /**
   * 生命周期函数--监听页面显示
   */
  onShow() {

  },

  /**
   * 生命周期函数--监听页面隐藏
   */
  onHide() {

  },

  /**
   * 生命周期函数--监听页面卸载
   */
  onUnload() {

  },

  /**
   * 页面相关事件处理函数--监听用户下拉动作
   */
  onPullDownRefresh() {

  },

  /**
   * 页面上拉触底事件的处理函数
   */
  onReachBottom() {

  },

  /**
   * 用户点击右上角分享
   */
  onShareAppMessage() {

  }
})