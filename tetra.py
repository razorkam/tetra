import terminatorlib.plugin as plugin
from gi.repository import Gtk, Gdk  # dyn import
import requests
# import GoogleUndocumentedTranslator as gut


AVAILABLE = ['Tetra']


class Tetra(plugin.MenuItem):
    config = None
    SELECTION = Gdk.SELECTION_PRIMARY  # Gdk current selection ATOM

    def __init__(self):
        super(Tetra, self).__init__()
        self._translator = Translator()

    def callback(self, menuitems, menu, terminal):
        translate_item = Gtk.MenuItem('Text for translation')
        menuitems.append(translate_item)
        menu.connect("map", self.update_item_label, translate_item)

    def update_item_label(self, menu, item):
        selected_text = Gtk.Clipboard.get(Tetra.SELECTION).wait_for_text()
        translated_text = self._translator.translate(selected_text)
        item.set_label(translated_text)


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