function addCard() {
    
	if (window.XMLHttpRequest){
		// code for IE7+, Firefox, Chrome, Opera, Safari
		xmlhttp = new XMLHttpRequest();
	} 
	else {
		// code for IE6, IE5
		xmlhttp = new ActiveXObject("Microsoft.XMLHTTP");
	}
	xmlhttp.onreadystatechange = function(){
		if (this.readyState == 4 && this.status == 200) {
			$('#form-message').text('dodano pomyślnie!');
		}
		else{
			$('#form-message').text('dodano pomyślnie!');
		}
	};
	xmlhttp.open("POST","dodajsub.php",true);
	xmlhttp.send();
}

$('.addBtn').click(addCard);