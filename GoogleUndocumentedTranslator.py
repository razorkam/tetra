import requests


class Translator:

    URL = "https://translate.googleapis.com/translate_a/single"
    HEADERS = {'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.11 (KHTML, like Gecko) Chrome/23.0.1271.64 Safari/537.11',
               'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8',
               'Accept-Encoding': 'none',
               'Connection': 'keep-alive'
               }

    def __init__(self):
        self._params = {  #just auto->ru now
            'client' : 'gtx',
            'sl' : 'auto',
            'tl' : 'ru',
            'dt' : 't'
        }

    def translate(self, source_text):
        self._params['q'] = source_text
        r = requests.get(url=Translator.URL, headers=Translator.HEADERS, params=self._params)
        translated_text = r.json()[0][0][0]
        return translated_text

