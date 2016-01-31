from django.shortcuts import render_to_response
from django.template import RequestContext
def main_page(request):
    return render_to_response(
        'main_page.html', RequestContext(request)
    )

from django.http import Http404
from django.contrib.auth.models import User
def user_page(request, username):
    try:
        user = User.objects.get(username=username)
    except:
        raise Http404('Requested user not found.')
    bookmarks = user.bookmark_set.all()
    variables = RequestContext(request, {
        'username': username,
        'bookmarks': bookmarks
    })
    return render_to_response('user_page.html', variables)

from django.http import HttpResponseRedirect
from django.contrib.auth import logout
def logout_page(request):
    logout(request)
    return HttpResponseRedirect('/')

from bookmarks.forms import *
def register_page(request):
    if request.method == 'POST':
        form = RegistrationForm(request.POST)
        if form.is_valid():
            user = User.objects.create_user(
                username=form.cleaned_data['username'],
                password=form.cleaned_data['password1'],
                email=form.cleaned_data['email']
            )
            return HttpResponseRedirect('/register/success/')
    else:
        form = RegistrationForm()
    variables = RequestContext(request, {
        'form': form
    })
    return render_to_response(
        'registration/register.html',
        variables
    )
