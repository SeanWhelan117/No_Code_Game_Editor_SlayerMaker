import anvil.server
import anvil.tables as tables
from anvil.tables import app_tables
import pandas as pd

anvil.server.connect("<your-app-key>") # Replace with your Anvil.works app key

@anvil.server.callable
def upload_csv(file_name):
  # Read the CSV file into a Pandas DataFrame
  df = pd.read_csv(file_name)

  # Create a new table in the Anvil.works database with the same name as the CSV file
  app_tables.create(file_name)

  # Insert the data from the DataFrame into the new table
  for index, row in df.iterrows():
    app_tables[file_name].add_row(**row.to_dict())
