var sys = require('sys');
var exec = require('child_process').exec;

//垃圾一键清理
function cleanall()
{
//从网页上获取用户输入的密码
var passwd=document.getElementById('passwd1').value;
//判断获取的密码是否为空，为空则弹出提示框
if(passwd =="" ||passwd==undefined ||passwd==null)
	alert("请输入当前用户密码！");
else{
var expr = "bash ./shell/cleanall.sh "+passwd;
exec(expr,function(error,stdout,stderr){
	a=document.getElementById("cleanall");
//把清理结果推送到网页上
	a.innerHTML=stdout;
	if(error!==null){
		console.log('exec error:'+error)
	}
});
}
}

