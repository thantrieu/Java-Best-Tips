import json


class Subject:
    def __init__(self, sid, sname, scredit, slesson):
        self.__id = sid
        self.__name = sname
        self.__credit = scredit
        self.__lesson = slesson

    def __str__(self):
        return f'Subject[id={self.__id}, name={self.__name},' \
               f'credit={self.__credit}, lesson={self.__lesson}]'


def decode_subject(dct):
    if 'subject_id' in dct:
        subject_id = dct['subject_id']
        subject_name = dct['subject_name']
        subject_credit = dct['subject_credit']
        subject_lesson = dct['subject_lesson']
        return Subject(subject_id, subject_name, subject_credit, subject_lesson)
    else:
        return None


if __name__ == '__main__':
    source = 'data1.json'
    with open(source) as json_reader:
        data = json_reader.read()
        subject = json.loads(data, object_hook=decode_subject)
        print(subject)
