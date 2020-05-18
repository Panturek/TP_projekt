function sprawdz()
{
	var liczba = document.getElementById("pole").value;
	
	if(liczba > 0) document.getElementById("wynik").innerHTML="dodatnia";
	else document.getElementById("wynik").innerHTML="nie";
}