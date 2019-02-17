# BitConverter
A Qt Application to convert some currencies to the current Bitcoin rate

- The user enters a value followed by a whitespace and a currency (USD/EUR/GBP)  in the text box and then clicks the "PushButton" button.
- When the button is pressed, the tool makes a request to the API as described here : https://www.blockchain.com/fr/api/exchange_rates_api
- The API response is parsed and the result is displayed in the label as 'N BTC' (N being the value from the API call response)

@Author - Oded Neaman
