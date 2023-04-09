import os
import openai
openai.api_key = os.getenv("OPENAI_API_KEY")
completion = openai.ChatCompletion.create(
    model="gpt-3.5-turbo", 
    messages=[{"role":""}]
)
# write a code to implement quick_sort
def quick_sort(a, l, r):
    pass