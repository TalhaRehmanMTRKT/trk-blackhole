import dash
from dash import dcc, html
from dash.dependencies import Input, Output
import random

# Initialize Dash application
app = dash.Dash(__name__)

# Define the Flask server
server = app.server

# Define the layout of the application
app.layout = html.Div(
    children=[
        html.H1("Random Number Generator"),  # Heading
        html.Button("Generate", id="generate-button", n_clicks=0),  # Button to generate random number
        html.Div(id="output-div")  # Placeholder for displaying generated number
    ]
)

# Callback function to generate random number upon button click
@app.callback(
    Output("output-div", "children"),  # Output component
    Input("generate-button", "n_clicks")  # Input component
)
def generate_random_number(n_clicks):
    """
    Generate a random number between 1 and 100 upon button click.

    Args:
        n_clicks (int): Number of times the button has been clicked.

    Returns:
        str: String displaying the generated random number.
    """
    if n_clicks > 0:
        random_number = random.randint(1, 100)
        return f"Generated number: {random_number}"
    else:
        return ""

def TestFUnctions_number(n_clicks):
    """
    Generate a random number between 1 and 100 upon button click.

    Args:
        n_clicks (int): Number of times the button has been clicked.

    Returns:
        str: String displaying the generated random number.
    """
    if n_clicks > 0:
        random_number = random.randint(1, 100)
        return f"Generated number: {random_number}"
    else:
        return ""

def I_change_the_name(n_clicks):
    """
    Generate a random number between 1 and 100 upon button click.

    Args:
        n_clicks (int): Number of times the button has been clicked.

    Returns:
        str: String displaying the generated random number.
    """
    if n_clicks > 0:
        random_number = random.randint(1, 100)
        return f"Generated number: {random_number}"
    else:
        return ""

def test_functionfor(n_clicks):
    """
    Generate a random number between 1 and 100 upon button click.

    Args:
        n_clicks (int): Number of times the button has been clicked.

    Returns:
        str: String displaying the generated random number.
    """
    if n_clicks > 0:
        random_number = random.randint(1, 100)
        return f"Generated number: {random_number}"
    else:
        return ""
"""
"""
# Main function to run the application
if __name__ == "__main__":
    app.run_server(debug=True)
