var komunikat = "Dostęp tylko dla zalogowanych użytkowników";

function event()
{
	alert(komunikat);
}

function LOAD(){
	var obj = document.getElementById("fiszkinieok")
	if(typeof(obj)!='undefined' && obj != null)
		obj.onclick=event;
}

window.onload = LOAD;
