// Celsius to Fahrenheit and vice versa
function celsiusToFahrenheit(id){
    const celsius = parseFloat(document.getElementById(id).innerText);// collects the temperature values
    const fahrenheit = (celsius * 9/5) + 32;
    document.getElementById(id).innerText = `${fahrenheit.toFixed(1)}`;
}
function fahrenheitToCelsius(id){
    const fahrenheit = parseFloat(document.getElementById(id).innerText);
    const celsius = (fahrenheit - 32) * 5 / 9;
    document.getElementById(id).innerText = `${celsius.toFixed(1)}`;
}
let unit_celsius = true; // Used as a swtich 
function convertToFahrenheit() {
    if (unit_celsius){
        celsiusToFahrenheit('temp_1');
        celsiusToFahrenheit('temp_2');
        celsiusToFahrenheit('temp_3');
        celsiusToFahrenheit('temp_4');
        unit_celsius = false;
        document.getElementById('units').innerText = `F`;
        }
    else {      
        fahrenheitToCelsius('temp_1');
        fahrenheitToCelsius('temp_2');
        fahrenheitToCelsius('temp_3');
        fahrenheitToCelsius('temp_4');             
        unit_celsius = true;
        document.getElementById('units').innerText = `C`;        
        }            
    }
// Search Functionality 
let searchUrl = ""
document.getElementById('searchInput').addEventListener('keypress', function(event) {
    if (event.key === 'Enter') {
        const query = this.value;
        const baseUrl = window.location.origin; // Gets the current base URL
        searchUrl = `${baseUrl}/${encodeURIComponent(query)}`; // Construct the new URL  
        event.preventDefault(); // Prevents default redirection to base url
        window.location.href = searchUrl; // Redirect to the new URL
    }
});
