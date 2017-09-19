import requests
import logging


class Translator:

    URL = "https://translate.googleapis.com/translate_a/single"
    HEADERS = {'User-Agent': 'Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:55.0) Gecko/20100101 Firefox/55.0',
               'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8',
               'Accept-Encoding': 'none',
               'Connection': 'keep-alive'
               }
    LOGNAME = "tetra_GUT.log"
    LANGUAGES = [
        'auto', 'af', 'am', 'ar', 'az', 'be', 'bg', 'bn', 'bs', 'ca', 'ceb', 'co', 'cs', 'cy', 'da', 'de',
        'el', 'en', 'eo', 'es', 'et', 'eu', 'fa', 'fi', 'fr', 'fy', 'ga', 'gd', 'gl', 'gu', 'ha', 'haw',
        'hi', 'hmn', 'hr', 'ht', 'hu', 'hy', 'id', 'ig', 'is', 'it', 'iw', 'ja', 'jw', 'ka', 'kk', 'km',
        'kn', 'ko', 'ku', 'ky', 'la', 'lb', 'lo', 'lt', 'lv', 'mg', 'mi', 'mk', 'ml', 'mn', 'mr', 'ms',
        'mt', 'my', 'ne', 'nl', 'no', 'ny', 'pa', 'pl', 'ps', 'pt', 'ro', 'ru', 'sd', 'si', 'sk', 'sl',
        'sm', 'sn', 'so', 'sq', 'sr', 'st', 'su', 'sv', 'sw', 'ta', 'te', 'tg', 'th', 'tl', 'tr', 'uk',
        'ur', 'uz', 'vi', 'xh', 'yi', 'yo', 'zn-CN', 'zn-TW', 'zu'
    ]

    def __init__(self):
        self._params = {  #just auto->ru now
            'client': 'gtx',
            'sl': 'auto',
            'tl': 'ru',
            'dt': 't'
        }
        logging.basicConfig(filename=Translator.LOGNAME, level=logging.ERROR)
        logging.Formatter(fmt='%(asctime)s')

    def translate(self, source_text):
        self._params['q'] = source_text
        try:
            r = requests.get(url=Translator.URL, headers=Translator.HEADERS, params=self._params)
            sentences_list = r.json()[0]
        except Exception as ex:
            logging.error(ex.message)
            return "Tetra plugin: error occured. View {logname} for more details"\
                .format(logname=Translator.LOGNAME)
        translated_text = ""
        for snt in sentences_list:
            translated_text += snt[0]
        return translated_text

    def get_tl(self):
        return self._params['tl']

    def get_sl(self):
        return self._params['sl']

    def set_tl(self, tl):
        self._params['tl'] = tl

    def set_sl(self, sl):
        self._params['sl'] = sl