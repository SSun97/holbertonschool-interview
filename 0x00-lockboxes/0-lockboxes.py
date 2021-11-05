#!/usr/bin/python3
""" Interview questions collection """


def canUnlockAll(boxes):
    """ You have n number of locked boxes in front of you. Each box is numbered sequentially
    from 0 to n - 1 and each box may contain keys to the other boxes. Write a method that
    determines if all the boxes can be opened. """

    key_list = []

    for key in boxes[0]:
        if key in range(1, len(boxes)):
            key_list.append(key)
    for key in key_list:
        for key2 in boxes[key]:
            if key2 not in key_list and key2 in range(1, len(boxes)):
                key_list.append(key2)
    return all(box_opened in key_list for box_opened in range(1, len(boxes)))
