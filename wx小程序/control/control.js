// pages/control/control.js
Page({

  /**
   * 页面的初始数据
   */
  data: {
    // 服务器地址
    url:"",
    // 已选择的颜色列表
    tapcolor: [],
    // 颜色数据
    colors: ["red", "pink", "green", "blue"]
  },

  /**
   * 颜色数据请求                                                         （get................）
  */
  getData(){
    wx.request({
      url: `${this.data.url}/getdata`,
      success:(res)=>{
        this.setData({
          colors:res.data.color
        })
      }
    })
  },

  carry(e){
    // 从事件对象中获取当前点击元素的颜色数据
    let CarryColor=e.currentTarget.dataset.color
    let getcolors=this.data.tapcolor
    getcolors.push(CarryColor)
    this.setData({
      tapcolor:getcolors,
    })
    // 检查已选择的颜色数量是否达到 2 个
    if (this.data.tapcolor.length>=2) {
      // 当选择的颜色达到 2 个时，向服务器发送请求
      // console.log(getcolors);
      wx.request({
        url: `${this.data.url}/putdata`,
        data:{
          start:getcolors[0],
          stop:getcolors[1]
        },
        success:(res)=>{
          // console.log(res.data);
          wx.showToast({
            title: '发送成功',
          })
        }
      })
      // 请求发送完成后，清空已选择的颜色列表
      this.setData({
        tapcolor:[],
      })
    }
  },
  /**
   * 生命周期函数--监听页面加载
   */
onLoad(options) {
  //获取页面参数
  if(options.url) {
    this.setData({
      url: options.url
    })
  }
  //请求颜色数据
  this.getData()
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